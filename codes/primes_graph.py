# Author: Khaled Alam (khaledalam.net@gmail.com)
# some lines from ref: stackoverflow

import matplotlib.pyplot as plt
import matplotlib
import numpy as np

# import threading  # Matplotlib is not thread safe
import multiprocessing
import time
import random


def all_prime(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

def prime_plot(n):
    '''
    Takes on argument (n), which is a number > 2 and produces a list of all primes up to n.
    Will then show on a plot the primes vs all numbers in range n.
    '''
    N = int(np.sqrt(n))
    if N*N != n:
        raise ValueError("Need a square grid.")

    font = {
        'family' : 'Times New Roman',
        'weight' : 'bold',
        'size'   : 100 / N 
    }

    matplotlib.rc('font', **font)

    primes = np.array(all_prime(n)).astype(int)
    data = np.zeros(n)
    data[primes] = 1
    data = data.reshape(N,N)

    fig, ax = plt.subplots()
    ax.imshow(data, cmap="gray_r")

    for p in primes:
        ax.text(p%N, p//N, p, color="w", ha="center", va="center")

    plt.savefig('primes_' + str(N) + 'x' + str(N) + '.png')
    plt.close()



if __name__ == "__main__": 

    q = multiprocessing.Queue()
    
    # Generate primes figures [i*i] where 2 <= i <= 100

    for i in range(2, 101):
        
        print("[ixi] i=" + str(i))
        #Create and start the simulation process
        process=multiprocessing.Process(None,prime_plot,args=(i*i,))
        process.start()
        process.join
