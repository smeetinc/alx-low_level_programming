/**
 * op_add - function to add
 * @a: for num1
 * @b: for num2
 * Return: sum of num1 and num2
 */

int op_add(int a, int b)
{
	int sum;

	sum = a + b;
	return (sum);
}

/**
 * op_sub - substraction function
 * @a: for num1
 * @b: for num2
 * Return: result of difference
 */

int op_sub(int a, int b)
{
	int diff;

	diff = a - b;
	return (diff);
}

/**
 * op_mul - multiply numbers
 * @a: for num1
 * @b: for num2
 * Return: mul result
 */

int op_mul(int a, int b)
{
	int mul;

	mul = a * b;
	return (mul);
}

/**
 * op_div - divide numbers
 * @a: for num1
 * @b: for num2
 * Return: div result
 */

int op_div(int a, int b)
{
	int div;

	div = a / b;
	return (div);
}

/**
 * op_mod - get remainder
 * @a: for num1
 * @b: for num2
 * Return: mod result
 */

int op_mod(int a, int b)
{
	return (a % b);
}
