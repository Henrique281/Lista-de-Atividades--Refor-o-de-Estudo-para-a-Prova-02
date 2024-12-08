import matplotlib.pyplot as plt # type: ignore

def quick_sort(arr, low, high, steps):
    if low < high:
        pi = partition(arr, low, high, steps)
        quick_sort(arr, low, pi - 1, steps)
        quick_sort(arr, pi + 1, high, steps)

def partition(arr, low, high, steps):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    steps.append(arr.copy())
    return i + 1

def merge(arr, l, m, r, steps):
    n1 = m - l + 1
    n2 = r - m
    L = arr[l:m + 1]
    R = arr[m + 1:r + 1]
    i = j = k = l

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1
    
    steps.append(arr.copy())

def merge_sort(arr, l, r, steps):
    if l < r:
        m = (l + r) // 2
        merge_sort(arr, l, m, steps)
        merge_sort(arr, m + 1, r, steps)
        merge(arr, l, m, r, steps)

def selection_sort(arr, steps):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        steps.append(arr.copy())

def plot_steps(steps, algorithm_name):
    for i, step in enumerate(steps):
        plt.figure(figsize=(10, 6))
        plt.bar(range(len(step)), step, color='skyblue')
        plt.title(f'{algorithm_name} - Etapa {i + 1}')
        plt.xlabel('Índice')
        plt.ylabel('Valor')
        plt.savefig(f'{algorithm_name}_step_{i + 1}.png')
        plt.close()

if __name__ == '__main__':
    arr1 = [10, 80, 30, 90, 40, 50, 70]
    quick_sort_steps = []
    quick_sort(arr1, 0, len(arr1) - 1, quick_sort_steps)
    plot_steps(quick_sort_steps, "Quick Sort")

    arr2 = [10, 80, 30, 90, 40, 50, 70]
    merge_sort_steps = []
    merge_sort(arr2, 0, len(arr2) - 1, merge_sort_steps)
    plot_steps(merge_sort_steps, "Merge Sort")

    arr3 = [10, 80, 30, 90, 40, 50, 70]
    selection_sort_steps = []
    selection_sort(arr3, selection_sort_steps)
    plot_steps(selection_sort_steps, "Selection Sort")
