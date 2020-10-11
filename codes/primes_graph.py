import matplotlib.pyplot as plt
import numpy as np

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

    primes = np.array(all_prime(n)).astype(int)
    data = np.zeros(n)
    data[primes] = 1
    data = data.reshape(N,N)

    fig, ax = plt.subplots()
    ax.imshow(data, cmap="gray_r")

    for p in primes:
        ax.text(p%N, p//N, p, color="w", ha="center", va="center")

    plt.show()

prime_plot(25)