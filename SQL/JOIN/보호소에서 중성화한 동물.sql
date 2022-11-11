SELECT A.ANIMAL_ID, A.ANIMAL_TYPE, A.NAME
FROM ANIMAL_INS A
JOIN ANIMAL_OUTS B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE A.SEX_UPON_INTAKE LIKE "INTACT%" AND (B.SEX_UPON_OUTCOME LIKE "SPAYED%" OR B.SEX_UPON_OUTCOME LIKE "NEUTERED%")
ORDER BY A.ANIMAL_ID;