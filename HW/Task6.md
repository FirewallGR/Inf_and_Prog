## Задание 6

Разработать программу, позволяющую выполнять расчет значений для некоторого набора функций в заданной точке с заданной погрешностью за счет разложения этих функций в ряд Тейлора.

Программа должна работать в двух режимах:
1. Однократный расчет функции в заданной точке.
2. Серийный эксперимент.

При работе в режиме 1 пользователь должен иметь возможность:
* выбрать функцию,
* задать точку x, в которой необходимо вычислить значение,
* задать точность вычисления (от 0.000001 и больше),
* задать число элементов ряда для выполнения расчета (N - от 1 до 1000).

Расчет оценки значения выбранной функции выполняется либо до достижения заданной точности, либо до исчерпания введенного числа слагаемых. По результатам расчета программа должна вывести следующую информацию:
* эталонное значение (полученное с использованием встроенных математических функций языка программирования С),
* вычисленную оценку значения функции,
* разницу между оценкой и эталонным значением,
* количество слагаемых, которое было вычислено.

При работе в режиме 2 пользователь должен иметь возможность:
* выбрать функцию,
* задать точку x, в которой необходимо вычислить значение,
* задать число экспериментов (NMax - от 1 до 25).

По результатам расчета программа должна вывести следующую информацию:
* эталонное значение (полученное с использованием встроенных математических функций языка программирования С),
* таблицу из NMax строк со следующими столбцами: кол-во слагаемых (от 1 до NMax), вычисленную оценку значения функции, разницу между оценкой и эталонным значением.

Технические требования:
* При разработке программы должен быть использован механизм функций языка С.
* В программе должен быть использован тип указатель на функцию.
* В программе желательно использовать модули.
* Каждый студент должен реализовать расчет функций sin(x), cos(x), exp(x) и одной уникальной функции из списка ниже. Номер требуемой функции совпадает с номером в списке группы.

Уникальные функции:
1.	Тангенс - tg(x)
2.	Гиперболический косинус - ch(x)
3.	Арксинус - arcsin(x)
4.	Косеканс - csc(x)
5.	Гиперболический котангенс - cth(x)
6.	Логарифм - ln(x)
7.	Логарифм от 1+х - ln (1+x)
8.	Секанс - sec(x)
9.	Квадратный корень из 1+х - (1+x)^1/2
10.	Арктангенс - arctg(x)
11.	Котангенс - ctg(x)
12.	Арккотангенс - arcctg(x)
13.	Гиперболический тангенс - th(x)
14.	Гиперболический синус - sh(x)
15.	Обратный гиперболический синус - arsh(x)
16.	Арккосинус - arccos(x)

