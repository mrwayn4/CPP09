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
struct PairComparator
{
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const
    {
        return a.first < b.first;
    }
};

void sortvector(std::vector<int>& v)
{
    int unpaired = -1;
    if (v.size() % 2)
    {
        unpaired = v.back();
        v.pop_back();
    }
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < v.size(); i += 2)
    {
        int largest = v[i];
        int lowest = v[i + 1];
        if (largest < lowest)
            std::swap(largest, lowest);
        pairs.push_back(std::make_pair(largest, lowest));
        std::cout << "Pair: " << largest << " " << lowest << std::endl;
    }
    std::sort(pairs.begin(), pairs.end(), PairComparator());
    displayPairsAfter(pairs);
}

void sort(std::vector<int>& v)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    sortvector(v);
}