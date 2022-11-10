#pragma once
#include <iostream>
#include "vmActionBase.hpp"

class opCodeBase
{
private:
    vmActionBase* action = nullptr; // Hold an action function pointer
public:
    opCodeBase();
    virtual ~opCodeBase();
    virtual void do_action();
    virtual void set_action(vmActionBase* action);
    friend std::ostream& operator<<(std::ostream& os, const opCodeBase& opCode);
};
