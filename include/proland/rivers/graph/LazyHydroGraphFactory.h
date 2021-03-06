/*
 * Proland: a procedural landscape rendering library.
 * Copyright (c) 2008-2011 INRIA
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Proland is distributed under a dual-license scheme.
 * You can obtain a specific license from Inria: proland-licensing@inria.fr.
 */

/*
 * Authors: Eric Bruneton, Antoine Begault, Guillaume Piolat.
 */

#ifndef _PROLAND_LAZYHYDROGRAPHFACTORY_H
#define _PROLAND_LAZYHYDROGRAPHFACTORY_H

#include "proland/graph/producer/GraphProducer.h"

namespace proland
{

/**
 * A GraphProducer::GraphFactory that creates LazyHydroGraph.
 * @ingroup rivergraph
 * @author Antoine Begault
 */
PROLAND_API class LazyHydroGraphFactory : public GraphProducer::GraphFactory
{
public:
    /**
     * Creates a new LazyHydroGraphFactory.
     */
    LazyHydroGraphFactory();

    /**
     * Deletes this LazyHydroGraphFactory.
     */
    virtual ~LazyHydroGraphFactory();

    /**
     * Returns a new LazyHydroGraph.
     */
    virtual Graph *newGraph(int nodeCacheSize, int curveCacheSize, int areaCacheSize);
};

}

#endif
