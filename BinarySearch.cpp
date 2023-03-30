template<typename Iterator, typename T>
T binary_search(Iterator begin, Iterator end, T val)
{
    end--; // increase becouse end point to end elem + 1
    while (std::distance(begin, end) >= 0) {
        auto mid = begin;
        std::advance(mid, (std::distance(begin, end)) / 2);
      
        if (*mid == val)
            return *mid;
        else if (std::distance(begin, end) == 0) // closed corner case when (end = begin) && (mid != vol)
            return 0;
        else if (*mid < val)
            std::advance(begin, std::distance(begin, mid) + 1);
        else
            std::advance(end, -1*(std::distance(mid, end)));
    }
    return 0;
}
