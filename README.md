# Калькулятор на языке Си (C)

## Небольшой учебный проект в виде калькулятора на языке Си (1 семестр, 1 курс)
**Автор: [AlexandrBal](https://github.com/AlexandrBal)**


### Инструкции по запуску (Windows)

1. Установите **GCC**, **GDB** и **GNU Make**.

   * [GCC](https://gcc.gnu.org/?utm_source=chatgpt.com)
   * GDB и GNU Make можно установить вместе с MinGW/MSYS2.

2. Добавьте пути к установленным инструментам в системную переменную `Path`.

3. Откройте **Git Bash** в папке проекта.

4. Для сборки проекта выполните:

```bash
make
```

После успешной сборки появится файл:

```text
calculator.exe
```

5. Для запуска калькулятора:

```bash
./calculator.exe
```

### Запуск тестов

Для запуска всех тестов выполните:

```bash
make tests
```

В процессе тестирования создаются файлы с фактическим результатом:

```text
tests/basic.actual
tests/errors.actual
```

Они сравниваются с соответствующими файлами `.expected`.

Если результаты совпадают, тест проходит успешно. Если результаты отличаются, `diff` покажет различия.


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