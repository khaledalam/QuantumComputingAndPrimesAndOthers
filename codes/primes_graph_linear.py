from matplotlib import pyplot as plt
import multiprocessing
import time


def prime_plot(max_):
    primeList = []

    for x in range(2, max_ + 1):
        isPrime = True
        for y in range (2, int(x ** 0.5) + 1):
            if x % y == 0:
                isPrime = False
                break
        if isPrime:
            primeList.append(x)

    plt.plot(primeList, 'o')
    plt.savefig('linear/primes_linear_2_' + str(max_) + '.png')
    plt.close()




MAX_N = 200

if __name__ == "__main__": 

    q = multiprocessing.Queue()
    
    # Generate primes figures [i*i] where 2 <= i <= 100

    num = 10
    mx = 100000000
    
    while num < mx:
        
        print("up to: " + str(num))
        #Create and start the simulation process
        process=multiprocessing.Process(None,prime_plot,args=(num,))
        process.start()
        process.join
        num *= 10
        
        # Maximum number of clients reachedUnable to init server: Could not connect: Connection refused  
        # (solution: increase sleep)
        time.sleep(.3) 