# Калькулятор на языке Си (C)

## Небольшой учебный проект в виде калькулятора на языке Си (1 семестр, 1 курс)
**Автор: [AlexandrBal](https://github.com/AlexandrBal)**


### Инструкции по запуску (Windows):
- Установите gcc и gdb: 
[GCC](https://gcc.gnu.org/?utm_source=chatgpt.com)
- Добавьте их в переменные среды Path
- В терминале напишите:
```
gcc main.c -o main.exe
./main.exe
```

### Поддерживаемые операции:
- `+` - сложение;
- `-` - вычитание;
- `*` - умножение;
- `/` - деление;
- `^` - возведение в степень;
- `H` - помощь/доп. информация;
- `N` - выход;

### Пример использования:
```
~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
Welcome to the calculator!
For more information press H
~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
Enter an operator: +
67 78
145.00
Enter an operator: -
45 89
-44.00
Enter an operator: *
4 8
32.00
Enter an operator: H
Available operators: H, +, -, *, /, ^, N
First enter an operator, then enter two numbers
To exit, enter N
Enter an operator: N
Thank you! Good day!
```