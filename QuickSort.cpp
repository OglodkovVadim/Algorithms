template<typename T>
std::vector<T> operator+(std::vector<T> arr1, std::vector<T> arr2)
{
    for (int i = 0; i < arr2.size(); i++)
        arr1.push_back(arr2[i]);

    return arr1;
    
}

template<typename T>
std::vector<T> quick(std::vector<T>& arr)
{
    if (arr.size() < 2)
        return arr;
    else {
        std::vector<T> left;
        std::vector<T> right;

        T p = arr[0];
        for (int i = 1; i < arr.size(); i++)
            arr[i] < p ? left.push_back(arr[i]) : right.push_back(arr[i]);

        return quick(left) + std::vector<T>{p} + quick(right);
    }
}
