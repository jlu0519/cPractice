# C Format Specifiers Reference Guide

This is a concise reference for `printf()` and `scanf()` format specifiers in C.

---

## 1. Integer Format Specifiers

| Specifier | Type              | Example       | Description                        |
|-----------|-------------------|---------------|------------------------------------|
| `%d`      | `int`             | `printf("%d", 42);` | Signed decimal integer             |
| `%i`      | `int`             | `printf("%i", 42);` | Same as `%d`                        |
| `%u`      | `unsigned int`    | `printf("%u", 42);` | Unsigned decimal integer           |
| `%x`      | `unsigned int`    | `printf("%x", 255);` | Unsigned hexadecimal (lowercase)   |
| `%X`      | `unsigned int`    | `printf("%X", 255);` | Unsigned hexadecimal (uppercase)   |
| `%o`      | `unsigned int`    | `printf("%o", 10);` | Unsigned octal                     |

---

## 2. Floating-Point Format Specifiers

| Specifier | Type              | Example             | Description                          |
|-----------|-------------------|---------------------|--------------------------------------|
| `%f`      | `float` / `double`| `printf("%f", 3.14);` | Decimal floating-point               |
| `%F`      | `float` / `double`| `printf("%F", 3.14);` | Same as `%f` (uppercase form)        |
| `%e`      | `float` / `double`| `printf("%e", 3.14);` | Scientific notation (lowercase)      |
| `%E`      | `float` / `double`| `printf("%E", 3.14);` | Scientific notation (uppercase)      |
| `%g`      | `float` / `double`| `printf("%g", 3.14);` | Auto `%f` or `%e` depending on value |
| `%G`      | `float` / `double`| `printf("%G", 3.14);` | Auto `%F` or `%E`                    |

---

## 3. Character and String Format Specifiers

| Specifier | Type         | Example               | Description            |
|-----------|--------------|-----------------------|------------------------|
| `%c`      | `char`       | `printf("%c", 'A');`  | Single character       |
| `%s`      | `char*`      | `printf("%s", "Hi");` | Null-terminated string |

---

## 4. Pointer Format Specifier

| Specifier | Type     | Example                    | Description        |
|-----------|----------|----------------------------|--------------------|
| `%p`      | `void*`  | `printf("%p", ptr);`       | Print memory address (pointer) |

---

## 5. Miscellaneous Format Specifiers

| Specifier | Description                        |
|-----------|------------------------------------|
| `%%`      | Prints a literal `%` character     |

---

## 6. Length Modifiers (used with specifiers)

| Modifier | Used With         | Meaning                         |
|----------|-------------------|---------------------------------|
| `h`      | `%hd`, `%hu`      | `short` or `unsigned short`     |
| `l`      | `%ld`, `%lf`      | `long` or `double`              |
| `ll`     | `%lld`, `%llu`    | `long long`                     |
| `L`      | `%Lf`             | `long double`                   |
| `z`      | `%zu`             | `size_t`                        |

---

## 7. Common Scanf Format Specifiers

| Specifier | Type             | Example                 |
|-----------|------------------|-------------------------|
| `%d`      | `int*`           | `scanf("%d", &x);`      |
| `%f`      | `float*`         | `scanf("%f", &f);`      |
| `%lf`     | `double*`        | `scanf("%lf", &d);`     |
| `%c`      | `char*`          | `scanf("%c", &c);`      |
| `%s`      | `char[]`         | `scanf("%s", str);`     |

---

## 8. Width and Precision in printf

You can control width and precision in floating-point output:

```c
printf("%10.2f", 3.14159); // Output: "      3.14"
