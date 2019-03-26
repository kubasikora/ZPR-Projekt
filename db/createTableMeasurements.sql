CREATE TABLE public.measurements
(
    measurement_id bigserial NOT NULL,
    value double precision NOT NULL,
    timestamp timestamp with time zone NOT NULL,
    device_id bigserial NOT NULL,
    CONSTRAINT measurement_id PRIMARY KEY (measurement_id),
    CONSTRAINT device_id FOREIGN KEY (device_id)
        REFERENCES public.devices (device_id) MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
WITH (
    OIDS = FALSE
);

ALTER TABLE public.measurements
    OWNER to zpr;