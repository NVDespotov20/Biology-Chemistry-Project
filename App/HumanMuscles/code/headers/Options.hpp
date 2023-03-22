#pragma once

class Options
{
public:
    ~Options();
    void drawOptions();
    static std::shared_ptr<Options> getInstantiation();
private:
    static std::shared_ptr<Options> instantiate_;

    Options();
    void load();
    void unload();
};