/*  =========================================================================
    mdp.h - public API for client and worker applications

    -------------------------------------------------------------------------
    Copyright (c) 1991-2012 iMatix Corporation <www.imatix.com>
    Copyright other contributors as noted in the AUTHORS file.

    This file is part of the Majordomo Project: http://majordomo.zeromq.org,
    an implementation of rfc.zeromq.org/spec:18/MDP (MDP/0.2) in C.

    This is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or (at
    your option) any later version.

    This software is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
    =========================================================================
*/

#ifndef __MDP_H_INCLUDED__
#define __MDP_H_INCLUDED__

#define MDP_VERSION_MAJOR 1
#define MDP_VERSION_MINOR 0
#define MDP_VERSION_PATCH 0

#define MDP_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define MDP_VERSION \
    MDP_MAKE_VERSION(MDP_VERSION_MAJOR, MDP_VERSION_MINOR, MDP_VERSION_PATCH)

//  Set up environment for the application
//
#include "czmq.h"

//  Classes listed in alphabetical order

#include "mdp_client.h"
#include "mdp_worker.h"

#endif
