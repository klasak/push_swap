# push_swap_new
Using radix sort on decimal numbers – explanation.

When completing your push_swap project you might decide to use radix sort. 

Check f.e. this tutorial <https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e> for a detailed explanation how it works. 

As explained in the link above, you can use radix sort algorithm for your push-swap project by first turning the numbers into binary and then by checking the bits whether they are 0 or 1.

I used a different approach, which I describe in this note.

I apply radix sort to the original arguments given as decimal numbers but at the same time I keep in mind how these numbers would look as binary numbers. Take f.e. decimal 10, in binary system: it would be 1010.

While sorting binary numbers you start from the last digit, you check whether it is 0 (then move it to stack B) or 1 (then you keep it in stack A). When you are done, you continue with the one before the last one digit etc.

How do I apply this to decimal numbers?

I observed the following:

1. The last digit in binary is the remainder (0 or 1) from the division of a decimal number by 2.
2. The one before the last one digit in binary is:
   
   0 if the remainder from the division of a decimal number by 4 is either 0 or 1.
   
   1 if the remainder from the division of a decimal number by 4 is either 2 or 3. 

	Just check the following numbers (*% denotes remainder from the division): 

	Decimal 4   Remainder 4 % 4 = 0*   	Binary 100  

	Decimal 5   Remainder 5 % 4 = 1 	  Binary 101  

	Decimal 6   Remainder 6 % 4 = 2 	  Binary 110  

	Decimal 7   Remainder 7 % 4 = 3 	  Binary 111  

	Decimal 8   Remainder 8 % 4 = 0 	  Binary 1000
	
	Etc..

3. The next digit to the left in binary is 0 if the remainder from the division of a decimal number by 8 is 0, 1, 2 or 3. It is 1 if the remainder is 4, 5,  6 or 7.

Etc.. So there is a pattern. 

Thus my implementation: 

I. Divide a decimal number by 2^digit (when digit = 1 for the last digit, 2 for the second last etc..) 

II. treat the current digit as 0 bit if the remainder falls into interval [0 : (2^digit)/2 - 1] 

III. and as 1 otherwise.

That is very easy to implement, for all digits just do the following:

div = 2^(digit);

(operator ^ is unknown to C, so you need to code it yourself) 

i = 0; 

while (i < size of stack)

{

	remainder = decimal_number % div;

	if (remainder >= 0 && reminder <= ((div / 2) - 1))

		push to stack B

	else

		rotate stack A

	i++;

}

Sorted!
