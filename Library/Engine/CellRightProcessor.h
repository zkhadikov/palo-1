/* 
 *
 * Copyright (C) 2006-2014 Jedox AG
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License (Version 2) as published
 * by the Free Software Foundation at http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * If you are developing and distributing open source applications under the
 * GPL License, then you are free to use Palo under the GPL License.  For OEMs,
 * ISVs, and VARs who distribute Palo with their products, and do not license
 * and distribute their source code under the GPL, Jedox provides a flexible
 * OEM Commercial License.
 *
 * \author Jiri Junek, qBicon s.r.o., Prague, Czech Republic
 * 
 *
 */

#ifndef OLAP_CELLRIGHT_PROCESSOR_H
#define OLAP_CELLRIGHT_PROCESSOR_H 1

#include "palo.h"
#include "Engine/EngineBase.h"
#include "Engine/Streams.h"

namespace palo {

class SERVER_CLASS CellRightProcessor : public ProcessorBase {
public:
	CellRightProcessor(PCubeArea cubeArea, PUser user, bool forPropertyCube);
	virtual ~CellRightProcessor() {}

	virtual bool next();
	virtual const CellValue &getValue();
	virtual double getDouble();
	virtual const IdentifiersType &getKey() const;
	virtual const GpuBinPath &getBinKey() const;
	virtual void reset();
	//virtual bool move(const IdentifiersType &key, bool *found); // TODO: -jj implement for better performance if needed

private:
	PCubeArea cubeArea;
	PUser user;
	CellValue cellValue;
	Area::PathIterator pathIt;
	CPPathTranslator pathTranslator;
	GpuBinPath binPath;
	bool forPropertyCube;
	IdentifiersType key;
	vector<User::RoleDbCubeRight> vRights;
};

}

#endif
