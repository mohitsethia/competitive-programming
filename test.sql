CREATE DATABASE pets;
USE pets;
CREATE TABLE cats(
    name VARCHAR(20),
    owner VARCHAR(20)
);
INSERT INTO cats (name, owner) VALUES ('V', 'K');
INSERT INTO cats (name, owner) VALUES ('D', 'Q');
SELECT * FROM cats;
SELECT name FROM cats where owner = 'K';
DROP DATABASE pets;
