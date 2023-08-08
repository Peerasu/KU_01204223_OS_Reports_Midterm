import time

start=0; end=0; time_input=0; time_output=0; time_for_loop=0

start = time.perf_counter()
input("input: ")
end = time.perf_counter()
time_input = (end-start)*pow(10, 6)

start = time.perf_counter()
print("test output time")
end = time.perf_counter()
time_output = (end-start)*pow(10, 6)

start = time.perf_counter()
for i in range(10000):
    pass
end = time.perf_counter()
time_for_loop = (end-start)*pow(10, 6)

print(f"time to receive input: {time_input} microseconds")
print(f"time to show output: {time_output} microseconds")
print(f"time to do for loop 10000 times: {time_for_loop} microseconds")

