# make sure that you already have file "test_IO.txt" in your path.

# if you don't have the file "test_IO.txt" in your path.
# uncomment and run this code ONLY in the first time.

# f = open("test_IO.txt", "x")
# f.write("Peerasu")

import time

def recursive(num):
    if num == 0:
        return 0
    return recursive(num-1)


start=0; end=0; time_input=0; time_output=0; time_for_loop=0; time_recursive=0

# count input time
start = time.perf_counter()
text = open("test_IO.txt", "r")
end = time.perf_counter()
time_input = (end-start)*pow(10, 6)

# count output time
start = time.perf_counter()
print(text)
end = time.perf_counter()
time_output = (end-start)*pow(10, 6)

# count for-loop(100) time
start = time.perf_counter()
for i in range(100):
    pass
end = time.perf_counter()
time_for_loop = (end-start)*pow(10, 6)

# count recursive(100) time
start = time.perf_counter()
recursive(100)
end = time.perf_counter()
time_recursive = (end-start)*pow(10, 6)

print(f"time for input: {time_input} microseconds")
print(f"time for output: {time_output} microseconds")
print(f"time to do for loop 100 times: {time_for_loop} microseconds")
print(f"time to call recursive function 100 times: {time_recursive} microseconds")

text.close()

