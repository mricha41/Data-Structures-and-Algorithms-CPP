template <std::size_t arraySize, class T1>
void DisplayArray(Array<arraySize, T1> arr)
{
    assert(arr.Size() > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    std::size_t i;
    std::cout<<"Array size: "<<arr.Size()<<std::endl;
    std::cout<<"Elements in Array: "<<std::endl;
    for(i=0; i<arr.Size(); ++i)
    {
        i<arr.Size() ? std::cout<<arr[i]<<" " :
            std::cout<<arr[i];
    }
    std::cout<<"\n\n";
}

template <class T1>
void Swap(T1 &x, T1 &y)
{
    T1 temp;
    temp = x;
    x = y;
    y = temp;
}

template <std::size_t arraySize, class T1>
int LinearSearch(Array<arraySize, T1> arr, T1 key)
{
    assert(arr.Size() > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    for(std::size_t i = 0; i < arr.Size(); ++i)
    {
        if(key == arr[i])
            return i;
    }

    return -99;
}

//rationale: when searching for elements
//it is often the case that found elements
//are often searched again, so moving found elements
//further up to the front makes searching faster
template <std::size_t arraySize, class T1>
int LinearSearchWithTransposition(Array<arraySize, T1> &arr, T1 key)
{
    assert(arr.Size() > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    for(std::size_t i = 0; i < arr.Size(); ++i)
    {
        if(key == arr[i])
        {
            if(i > 0)
            {
                Swap(arr[i], arr[i - 1]);
                return i - 1;
            }

            return 0;
        }
    }

    return -99;
}

//rationale: when searching for elements
//moving found elements to the front
//makes searching constant time for repeated searches
template <std::size_t arraySize, class T1>
int LinearSearchMoveToFront(Array<arraySize, T1> &arr, T1 key)
{
    assert(arr.Size() > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    for(std::size_t i = 0; i < arr.Size(); ++i)
    {
        if(key == arr[i])
        {
            if(i > 0)
                Swap(arr[i], arr[0]);

            return 0;
        }
    }

    return -99;
}

template <std::size_t arraySize, class T1>
int BinarySearch(Array<arraySize, T1> arr, T1 key)
{
    assert(arr.Size() > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    int low, mid, high;
    low = 0;
    high = arr.Size() - 1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -99;
}

template <std::size_t arraySize, class T1>
int RecursiveBinarySearch(Array<arraySize, T1> arr, int low, int high, T1 key)
{
    assert(arr.Size() > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    int mid;
    if(low <= high)
    {
        mid = (low + high)/2;
        if(key == arr[mid])
            return mid;
        else if(key < arr[mid])
            return RecursiveBinarySearch<arraySize, T1>(arr, low, mid - 1, key);
        else
            return RecursiveBinarySearch<arraySize, T1>(arr, mid + 1, high, key);
    }
    return -99;
}

template <std::size_t arraySize, class T1>
void Reverse(Array<arraySize, T1> &arr)
{
    assert(arr.Size() > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    std::size_t i = arr.Size() - 1;
    std::size_t j = 0;
    for(; j<i; ++j,--i)
    {
        Swap(arr[i], arr[j]);
    }
}

template <std::size_t arraySize, class T1>
void Rearrange(Array<arraySize, T1> &arr)
{
    assert(arr.Size() > 0 &&
           "Your array is empty. This function requires a non-empty array.");

    std::size_t i = 0;
    std::size_t j = arr.Size() - 1;
    while(i < j)
    {
        while(i < arr.Size() && arr[i] < 0)
            ++i;
        while(j > 0 && arr[j] >= 0)
            --j;

        if(i < j)
            Swap(arr[i], arr[j]);
    }
}

template <std::size_t arrayNewSize, std::size_t arrayOneSize, std::size_t arrayTwoSize, class T1>
Array<arrayNewSize, T1> &Merge(Array<arrayOneSize, T1> &arr1, Array<arrayTwoSize, T1> &arr2)
{
    std::size_t i, j, k;
    i = j = k = 0;

    Array<arrayNewSize, T1> arr3;
    //fill with default values...
    //in this case it's templated so use 
    //value initialization for type T1
    for (std::size_t i = 0; i < arr1.Size() + arr2.Size(); ++i)
        arr3.Append(T1());
    
    while(i < arr1.Size() && j < arr2.Size())
    {
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    for(; i < arr1.Size(); ++i)
        arr3[k++] = arr1[i];
    for(; j < arr2.Size(); ++j)
        arr3[k++] = arr2[j];

    return arr3;
}

template <std::size_t arrayNewSize, std::size_t arrayOneSize, std::size_t arrayTwoSize, class T1>
Array<arrayNewSize, T1>& Union(Array<arrayOneSize, T1>& arr1, Array<arrayTwoSize, T1>& arr2)
{
    std::size_t i, j, k;
    i = j = k = 0;

    Array<arrayNewSize, T1> arr3;
    //fill with default values...
    //in this case it's templated so use 
    //value initialization for type T1
    for (std::size_t i = 0; i < arr1.Size() + arr2.Size(); ++i)
        arr3.Append(T1());

    while (i < arr1.Size() && j < arr2.Size())
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else if (arr2[j] < arr1[i])
            arr3[k++] = arr2[j++];
        else
        {
            //main difference from merge, 
            //when it's the case they're equal
            //just pick one and increment both indices
            arr3[k++] = arr1[i++];
            j++;
        }
    }

    for (; i < arr1.Size(); ++i)
        arr3[k++] = arr1[i];
    for (; j < arr2.Size(); ++j)
        arr3[k++] = arr2[j];

    //can't tell how many dups at first, so need
    //to trim the leftover elements after dups are discovered
    for (std::size_t d = arr1.Size() + arr2.Size(); d > k; --d)
        arr3.Remove(d);

    return arr3;
}

template <std::size_t arrayNewSize, std::size_t arrayOneSize, std::size_t arrayTwoSize, class T1>
Array<arrayNewSize, T1>& Intersection(Array<arrayOneSize, T1>& arr1, Array<arrayTwoSize, T1>& arr2)
{
    std::size_t i, j, k;
    i = j = k = 0;

    Array<arrayNewSize, T1> arr3;
    //fill with default values...
    //in this case it's templated so use 
    //value initialization for type T1
    for (std::size_t i = 0; i < arr1.Size() + arr2.Size(); ++i)
        arr3.Append(T1());

    while (i < arr1.Size() && j < arr2.Size())
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else //they're equal - so they intersect
        {
            arr3[k++] = arr1[i++];
            j++;
        }
    }

    //can't tell how many non-intersecting items at first, so need
    //to trim the leftover elements after they are discovered
    for (std::size_t d = arr1.Size() + arr2.Size(); d > k; --d)
        arr3.Remove(d);

    return arr3;
}

template <std::size_t arrayNewSize, std::size_t arrayOneSize, std::size_t arrayTwoSize, class T1>
Array<arrayNewSize, T1>& Difference(Array<arrayOneSize, T1>& arr1, Array<arrayTwoSize, T1>& arr2)
{
    std::size_t i, j, k;
    i = j = k = 0;

    Array<arrayNewSize, T1> arr3;
    //fill with default values...
    //in this case it's templated so use 
    //value initialization for type T1
    for (std::size_t i = 0; i < arr1.Size() + arr2.Size(); ++i)
        arr3.Append(T1());

    while (i < arr1.Size() && j < arr2.Size())
    {
        //copy items less than those
        //of the compared items in arr2
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else if (arr2[j] < arr1[i]) //otherwise move only j index forward
            j++;
        else
        {
            //when they're equal, move
            //both indices forward and do not copy
            i++;
            j++;
        }
    }

    //finally, copy any remaining elements
    //from first array but not the second array
    for (; i < arr1.Size(); ++i)
        arr3[k++] = arr1[i];

    //can't tell how many should be copied at first, so need
    //to trim the leftover elements after comparisons are made
    for (std::size_t d = arr1.Size() + arr2.Size(); d > k; --d)
        arr3.Remove(d);

    return arr3;
}