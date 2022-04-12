#一元二次求解
import math
def yyec(a, b, c):
    x1=(-b + math.sqrt(b**2-4*a*c))/(2*a)
    x2=(-b - math.sqrt(b**2-4*a*c))/(2*a)
    return x1,x2
#测试:x^2+2x+1
[x1,x2]=yyec(1,2,1)
print([x1,x2])
#一元二次方程求解结束

#hhh1