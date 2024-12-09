#ifndef WORSTFIT_H
#define WORSTFIT_H

#include "AllocationTechnique.h"

class WorstFit : public AllocationTechnique {
public:
    WorstFit(const std::vector<Partition> &partitions);

    static bool allocate(Process &process, std::vector<Partition> &partitions);

    bool deallocate(const int &process_id, std::vector<Process> &processes, std::vector<Partition> &partitions);

    void format(std::vector<Process> &processes, std::vector<Partition> &partitions);
};


#endif // WORSTFIT_H
