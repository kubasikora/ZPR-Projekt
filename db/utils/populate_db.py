#!/usr/bin/python3

import psycopg2
import datetime
import itertools
import math
import sys

from progress.bar import Bar


def date_generator():
    from_date = datetime.datetime.today()
    while True:
        yield from_date
        from_date = from_date - datetime.timedelta(seconds=10)

def value_generator(num, avg, amplitude):
    values = [avg] * num
    for i in range(len(values)):
        values[i] = values[i] + amplitude*math.sin(i*math.pi/10)
    return values

def create_data(num, avg, amplitude):
    values = value_generator(num, avg, amplitude)
    values = list(values)

    dates = itertools.islice(date_generator(), num)
    dates = list(dates)

    items = []
    for i in range(num):
        items.append((values[i], dates[i]))

    return items 

def get_bounds(deviceId):
    conn_str = "dbname='zpr' user='zpr' host='localhost' password='zpr'"
    try:
        conn = psycopg2.connect(conn_str)
    except:
        print("I am unable to connect to the database")
        exit(-1)

    cur = conn.cursor()
    cur.execute("SELECT min_value, max_value FROM Devices WHERE device_id = {}".format(deviceId))
    rows = cur.fetchall()
    return rows[0]


def insert(data, deviceId):
    num = len(data)
    conn_str = "dbname='zpr' user='zpr' host='localhost' password='zpr'"
    try:
        conn = psycopg2.connect(conn_str)
    except:
        print("I am unable to connect to the database")
        exit(-1)

    bar = Bar("Populating db with measurements from device {}".format(deviceId), max=num)
    cur = conn.cursor()
    for record in data:    
        dt = record[1]
        pg_datetime = psycopg2.Timestamp(dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second)
        sql = "INSERT INTO Measurements VALUES (default, {0}, {1}, {2});".format(round(record[0], 2), pg_datetime, deviceId)
        cur.execute(sql)
        bar.next()
    
    conn.commit()
    cur.close()
    bar.finish()

NUMBER_OF_RECORDS = 10000
AMP_BOUNDING_VALUE = 0.3
devices = [1, 2, 3, 4]
for deviceId in devices:
    bounds = get_bounds(deviceId)

    average = (bounds[1] - bounds[0]) / 2
    amplitude = bounds[1] - average
    amplitude = amplitude * AMP_BOUNDING_VALUE

    items = create_data(NUMBER_OF_RECORDS, average, amplitude)
    insert(items, deviceId)
