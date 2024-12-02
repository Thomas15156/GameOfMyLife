#ifndef VIEW_H
#define VIEW_H

#include "Model.h"

class View {
    private:
    const Grid& grid;
public:
    View(const Grid& grid);
    void view_run_console() const;


};

#endif // VIEW_H
