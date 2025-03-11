#include "PmergeMe.hpp"

int parseargs(char **av, std::vector<int>& v, int ac)
{
    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        int nb;

        if (iss >> nb && iss.eof())
        {
            if (nb < 0)
                return (0);
            v.push_back(nb); 
        }
        else
            return (0);
    }
    return (1);
}

void recursivesort_vector(std::vector<std::pair<int, int> >& pairs, size_t start, size_t end)
{
    if (start >= end)
        return;
    std::pair<int, int> pivot = pairs[end];
    size_t i = start;
    for (size_t j = start; j < end; j++)
    {
        if (pairs[j].first < pivot.first)
        {
            std::swap(pairs[i], pairs[j]);
            i++;
        }
    }
    std::swap(pairs[i], pairs[end]);
    if (i > 0)
        recursivesort_vector(pairs, start, i - 1);
    recursivesort_vector(pairs, i + 1, end);
}

void recursivesort_deque(std::deque<std::pair<int, int> >& pairs, size_t start, size_t end)
{
    if (start >= end)
        return;
    std::pair<int, int> pivot = pairs[end];
    size_t i = start;
    for (size_t j = start; j < end; j++)
    {
        if (pairs[j].first < pivot.first)
        {
            std::swap(pairs[i], pairs[j]);
            i++;
        }
    }
    std::swap(pairs[i], pairs[end]);
    if (i > 0)
        recursivesort_deque(pairs, start, i - 1);
    recursivesort_deque(pairs, i + 1, end);
}

std::vector<int> jacob_algo_vector(int size)
{
    std::vector<int> jacobsthal;
    std::vector<int> jacobindex;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);

    int z = 0;
    for(size_t i = 3; z < size; i++)
    {
        z = jacobsthal[i - 1] + (2 * jacobsthal[i - 2]);
        jacobsthal.push_back(z);
    }
    
    int x = 1;
    for(size_t i = 0; i < jacobsthal.size() ;i++)
    {
        if(jacobsthal[i] < size)
            jacobindex.push_back(jacobsthal[i]);
        int y = jacobsthal[i] -1;
        while(y > x)
        {
            if(y < size)
                jacobindex.push_back(y);
            y--;
        }
        x = jacobsthal[i];
    }

    return jacobindex;
}

std::deque<int> jacob_algo_deque(int size)
{
    std::deque<int> jacobsthal;
    std::deque<int> jacobindex;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);

    int z = 0;
    for(size_t i = 3; z < size; i++)
    {
        z = jacobsthal[i - 1] + (2 * jacobsthal[i - 2]);
        jacobsthal.push_back(z);
    }
    
    int x = 1;
    for(size_t i = 0; i < jacobsthal.size() ;i++)
    {
        if(jacobsthal[i] < size)
            jacobindex.push_back(jacobsthal[i]);
        int y = jacobsthal[i] -1;
        while(y > x)
        {
            if(y < size)
                jacobindex.push_back(y);
            y--;
        }
        x = jacobsthal[i];
    }

    return jacobindex;
}

void sortvector(std::vector<int>& v)
{
    int unpaired = -2;
    if (v.size() % 2)
    {
        unpaired = v.back();
        v.pop_back();
    }
    std::vector<int> jacobsthal(v.size());
    jacobsthal = jacob_algo_vector(v.size());
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < v.size(); i += 2)
    {
        int largest = v[i];
        int lowest = v[i + 1];
        if (largest < lowest)
            std::swap(largest, lowest);
        pairs.push_back(std::make_pair(largest, lowest));
    }
    recursivesort_vector(pairs, 0, pairs.size() - 1);
    std::vector<int> mainchain, pend;

    mainchain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); i++)
        mainchain.push_back(pairs[i].first);
    for (size_t i = 0; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);
    pend.erase(pend.begin());
    for (size_t i = 0; i < pend.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(mainchain.begin(), mainchain.end(), pend[i]);
        mainchain.insert(it, pend[i]);
    }
    if (unpaired != -2)
    {
        std::vector<int>::iterator it = std::lower_bound(mainchain.begin(), mainchain.end(), unpaired);
        mainchain.insert(it, unpaired);
    }
    std::cout << "After: ";
    for (size_t i = 0; i < mainchain.size(); i++)
        std::cout << mainchain[i] << " ";
    std::cout << std::endl;
}

void sortdeque(std::deque<int>& d)
{
    int unpaired = -2;
    if (d.size() % 2)
    {
        unpaired = d.back();
        d.pop_back();
    }
    std::deque<int> jacobsthal(d.size());
    jacobsthal = jacob_algo_deque(d.size());

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < d.size(); i += 2)
    {
        int largest = d[i];
        int lowest = d[i + 1];
        if (largest < lowest)
            std::swap(largest, lowest);
        pairs.push_back(std::make_pair(largest, lowest));
    }
    recursivesort_deque(pairs, 0, pairs.size() - 1);
    std::deque<int> mainchain, pend;

    mainchain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); i++)
        mainchain.push_back(pairs[i].first);
    for (size_t i = 0; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);
    pend.erase(pend.begin());

    for (size_t i = 0; i < pend.size(); i++)
    {
        std::deque<int>::iterator it = std::lower_bound(mainchain.begin(), mainchain.end(), pend[i]);
        mainchain.insert(it, pend[i]);
    }
    if (unpaired != -2)
    {
        std::deque<int>::iterator it = std::lower_bound(mainchain.begin(), mainchain.end(), unpaired);
        mainchain.insert(it, unpaired);
    }
    std::cout << "After: ";
    for (size_t i = 0; i < mainchain.size(); i++)
        std::cout << mainchain[i] << " ";
    std::cout << std::endl;
}


void sort(std::vector<int>& v)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    clock_t start = clock();
    sortvector(v);
    clock_t end = clock();
    double time = double(end - start) / (CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << time << "us" << std::endl;
    start = clock();
    std::deque<int> d(v.begin(), v.end());
    sortdeque(d);
    end = clock();
    time = double(end - start) / (CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of " << v.size() << " elements with std::deque : " << time << "us" << std::endl;
}