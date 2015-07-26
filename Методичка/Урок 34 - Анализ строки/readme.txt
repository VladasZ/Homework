использован класс Stack из прошлых домашних заданий - выполняет проверку на правильность расстановки скобок

функции:
 
	-string binaryCalculation(string expr) 
		- принимает выражения вида "a+b" в виде строки. Возвращает результат вычисления в виде строки.

	-inline bool isHook/Symbol(int i, string expr)
		- определяет является ли элемент массива i скобкой/символом.
		
	- int 	findNextHook,
		findPrevHook,
		findNextSympol,
		findPrevSymbol (int pos, string expr)
		- (см. название функции) ищет следующую/предыдущюю скобку/символ начинаю с индекса pos, если не находит возвращает -1.