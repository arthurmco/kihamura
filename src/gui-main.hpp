/*  GUI code entry point

    Copyright (C) 2016 Arthur M
*/

#ifndef _GUI_MAIN_HPP
#define _GUI_MAIN_HPP

#include "VideoProject.hpp"
#include "media/AnyMedia.hpp"

extern "C" {
    #include <gtk/gtk.h>
}

#define _(x) (x)

int gui_main(int argc, char** argv);


#endif /* end of include guard: _GUI_MAIN_HPP */
