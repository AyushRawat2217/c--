/*

infix- jisme operators are between the operands = a*b

prefix- in this operators are ahead of operands 
*ab

postfix - operands after operators
ab*


infix to postfix
operands ko result string mai  and operators ko separate stack mai daalte rho
jbh operators mai ek kam priority ka operatort top of stack aajein jyada priority ke
tbh operator wale stack se high priotiy wala operator
pop krke operand wale string mai daal do
and jbh closing barcket aaein toh keep popping the operators stack until u get a open bracket
last mai agr operands bachta hai toh pop krr krr ke daal do , main string mai


infix to prefix
pehle reverse krna hai , fir closing bracket ko open or open ko close krna
and at the end isko prefix to postfix ki trh solve krna hai
and last mai answer ko reverse krdena hai



postfix to infix
siply operations se operator stakc mai daalne hai
agr koi operator aat ahai toh
top ke two operands ko uss operator ke saath merge krke likh lena hai and bracket mai close krlena hai
and similarly krte jaana hai
and last mai stack mai merge hokr sirf ek elemnt bacha rhega usko hi return krdena hai
or merge ka imp part ye hai ki  ( last second elemnt  + operator + last elemt) , iss format mai hoga
prefix to indix mai ulta hoaega last second ki jgh last ye scene hai


postfix to prefix
operand aaya toh normal push kro
//if elemnt is an operator , put the operator before then take the last secoand the last element of stakc
 //then all alll three operator n last 2nd ele and last elemnt and push it into the stack


 prefix to postfix
 isme same upr wale ki trh hai bss format change hokr 
 last elemnt , last second , and operator iss format mai aajega



*/