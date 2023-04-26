#https://colab.research.google.com/drive/1L_2syN8Cqtyywm3MOkzCOXyfw3FuVxOc#scrollTo=zcirEKOgpWGk

import multiprocessing
import math

# funcion fibonacci con la tecnica de la memorizacion para mejorar el tiempo de ejecucion
def fibonacci(n, memo={}): 
    if n in memo:
      return memo[n]
    
    # Cálculo fibo con formula   
    memo[n]=math.trunc((pow((1+math.sqrt(5))/2,n) - pow((1-math.sqrt(5))/2,n))/math.sqrt(5))
    return memo[n]

if __name__ == '__main__':
    with multiprocessing.Pool() as pool:
        result = pool.map(fibonacci, range(1000))
    print(result)