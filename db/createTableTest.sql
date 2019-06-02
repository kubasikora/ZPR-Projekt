CREATE TABLE public.test
(
    testid integer NOT NULL DEFAULT nextval('test_testid_seq'::regclass),
    message character varying(255) COLLATE pg_catalog."default" NOT NULL,
    CONSTRAINT test_pkey PRIMARY KEY (testid)
)
WITH (
    OIDS = FALSE
)
TABLESPACE pg_default;

GRANT ALL ON TABLE public.test TO zpr;

INSERT INTO test VALUES (1, 'Hello world!');