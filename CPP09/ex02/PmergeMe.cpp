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

void displayPairsAfter(const std::vector<std::pair<int, int> >& pairs)
{
    for (size_t i = 0; i < pairs.size(); ++i)
        std::cout << "Pair after: " << pairs[i].first << " " << pairs[i].second << std::endl;
}

void sortvector(std::vector<int>& v)
{
    int unpaired = -2;
    if (v.size() % 2)
    {
        unpaired = v.back();
        v.pop_back();
    }
    std::vector<int> jacobsthal(v.size());//up tp length of v
    if (v.size() > 0)
        jacobsthal[0] = 0;
    if (v.size() > 1)
        jacobsthal[1] = 1;
    std::vector<int> jacobindex(v.size());
    jacobindex[0] = 0;
    jacobindex[1] = 1;
     // the for loop for the jacobsthal sequence
    for (size_t i = 2; i < v.size(); i++)
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2] + 1;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < v.size(); i += 2)
    {
        int largest = v[i];
        int lowest = v[i + 1];
        if (largest < lowest)
            std::swap(largest, lowest);
        pairs.push_back(std::make_pair(largest, lowest));
        // std::cout << "Pair: " << largest << " " << lowest << std::endl;
    }
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::pair<int, int> tmp = pairs[i];
        size_t j = i;
        while (j > 0 && pairs[j - 1].first > tmp.first)
        {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = tmp;
    }
    // displayPairsAfter(pairs);
    std::vector<int> mainchain, pend;

    mainchain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); i++)
        mainchain.push_back(pairs[i].first);
    for (size_t i = 0; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);
    pend.erase(pend.begin());
    // for (size_t i = 0; i < mainchain.size(); i++)
    //     std::cout << "Mainchain: " << mainchain[i] << std::endl;
    // for (size_t i = 0; i < pend.size(); i++)
    //     std::cout << "Pend: " << pend[i] << std::endl;
    for (size_t i = 0; i < pend.size(); i++)
    {
        if (static_cast<size_t>(jacobsthal[i]) < pend.size())
        {
            std::vector<int>::iterator it = std::lower_bound(mainchain.begin(), mainchain.end(), pend[i]);
            mainchain.insert(it, pend[jacobsthal[i]]);
        }
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
    std::deque<int> jacobsthal(d.size());//up tp length of d
    if (d.size() > 0)
        jacobsthal[0] = 0;
    if (d.size() > 1)
        jacobsthal[1] = 1;
    for (size_t i = 2; i < d.size(); i++)
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2] + 1;
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < d.size(); i += 2)
    {
        int largest = d[i];
        int lowest = d[i + 1];
        if (largest < lowest)
            std::swap(largest, lowest);
        pairs.push_back(std::make_pair(largest, lowest));
        // std::cout << "Pair: " << largest << " " << lowest << std::endl;
    }
    for (size_t i = 1; i < pairs.size(); i++)
    {
        std::pair<int, int> tmp = pairs[i];
        size_t j = i;
        while (j > 0 && pairs[j - 1].first > tmp.first)
        {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = tmp;
    }
    // displayPairsAfter(pairs);
    std::deque<int> mainchain, pend;

    mainchain.push_back(pairs[0].second);
    for (size_t i = 0; i < pairs.size(); i++)
        mainchain.push_back(pairs[i].first);
    for (size_t i = 0; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);
    pend.erase(pend.begin());
    // for (size_t i = 0; i < mainchain.size(); i++)
    //     std::cout << "Mainchain: " << mainchain[i] << std::endl;
    // for (size_t i = 0; i < pend.size(); i++)
    //     std::cout << "Pend: " << pend[i] << std::endl;
    for (size_t i = 0; i < pend.size(); i++)
    {
        if (static_cast<size_t>(jacobsthal[i]) < pend.size())
        {
            std::deque<int>::iterator it = std::lower_bound(mainchain.begin(), mainchain.end(), pend[i]);
            mainchain.insert(it, pend[jacobsthal[i]]);
        }
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