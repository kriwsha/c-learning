# Домашняя работа №1

### Задание:

1. Написать программу, определяющую, является ли заданный файл т.н. Rarjpeg-ом (изображением, в конец которого дописан архив), и выводящую список файлов в архиве, если заданный файл таковым является.
2. Для простоты подразумевается формат архива zip, а не rar.
3. Сторонние библиотеки не использовать.

###### Требования:
1. Создано консольное приложение, принимающее аргументом командной строки входной файл.
2. Приложение корректно обрабатывает ошибки доступа к файлу.
3. Приложение корректно подсчитывает и выводит на экран информацию о том, сколько раз в файле встречается каждое слово, которое есть в файле.
4. Код компилируется без warning'ов с ключами компилятора -Wall -Wextra -Wpedantic -std=c11.
5. Далее успешность определяется code review.

### Результат

###### Zip File:
````
input file path: ~\hw1\test\zipjpeg.jpg
this is zipjpeg
````

###### Non Zip File:
````
input file path: ~\hw1\test\non-zipjpeg.jpg
this is non-zipjpeg.
````