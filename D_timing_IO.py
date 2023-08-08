import time

def recursive(num):
    if num == 0:
        return 0
    return recursive(num-1)

start=0; end=0; time_IO=0; time_for_loop=0; time_recursive=0

start = time.perf_counter()
print("test I/O time")
end = time.perf_counter()
time_IO = (end-start)*pow(10, 6)

start = time.perf_counter()
for i in range(1000):
    pass
end = time.perf_counter()
time_for_loop = (end-start)*pow(10, 6)

start = time.perf_counter()
recursive(500)
end = time.perf_counter()
time_recursive = (end-start)*pow(10, 6)

print(f"time for I/O: {time_IO} microseconds")
print(f"time to do for loop 1000 times: {time_for_loop} microseconds")
print(f"time to call recursive function 500 times: {time_recursive} microseconds")

