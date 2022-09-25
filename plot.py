import matplotlib.pyplot as plt

if __name__ == '__main__':

    filepath = './data.txt'
    names = ["Selection Sort", "Bubble Sort" , "Bubble Escape", "Insertion Sort", "MergeSort", "QuickSort"]  
    x = list(range(1000, 20001, 1000))  # this is the range of input sizes tested
    with open(filepath, 'r') as file:
        for i, line in enumerate(file):
            y = list(map(int, line.split(',')))
            plt.plot(x, y, label=names[i])

    plt.xlabel('Input size')
    plt.ylabel('Time taken (ns)')
    plt.title('Comparison of sort procedures')
    plt.legend()
    plt.savefig('sorting.pdf')
    plt.show()


