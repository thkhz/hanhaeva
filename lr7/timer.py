import time
import math
from typing import List

def distance_py(a: List[float], b: List[float]) -> float:
    sum_sq = 0.0
    for x, y in zip(a, b):
        diff = x - y
        sum_sq += diff * diff
    return math.sqrt(sum_sq)

def total_time(iters: int, a: List[float], b: List[float]) -> None:
    start_time = time.time() 

    for i in range(iters):
        distance_py(a, b)  

    end_time = time.time()  
    time_taken = end_time - start_time  

    print(f"Итераций: {iters}")
    print(f"Общее время: {time_taken:.6f} секунд")
    

if __name__ == "__main__":
    a = [1.0, 2.0, 3.0]
    b = [4.0, 5.0, 6.0]

    for iters in (1_000_000, 10_000_000):
        total_time(iters, a, b)