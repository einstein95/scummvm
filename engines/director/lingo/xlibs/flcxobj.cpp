/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
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
 *
 */

#include "common/system.h"

#include "director/director.h"
#include "director/lingo/lingo.h"
#include "director/lingo/lingo-object.h"
#include "director/lingo/lingo-utils.h"
#include "director/lingo/xlibs/flcxobj.h"

/**************************************************
 *
 * USED IN:
 * Karma: Curse of the 12 Caves (Mac)
 *
 **************************************************/

/*
-- FLCPlayer
I      mNew
lSll   mPlay, fileName, x, y
lSlll  mVideo, fileName, x, y, delayT
lSllll  mStretch, fileName, x, y, w, h
l      mDispose
 */

namespace Director {

const char *FLCXObj::xlibName = "FLCxobj";
const char *FLCXObj::fileNames[] = {
	"FLCxobj",
	nullptr
};

static MethodProto xlibMethods[] = {
	{ "new",				FLCXObj::m_new,		 0, 0,	400 },
	{ "play",				FLCXObj::m_play,	 3, 3,	400 },
	{ "video",				FLCXObj::m_video,	 4, 4,	400 },
	{ "stretch",			FLCXObj::m_stretch,	 5, 5,	400 },
	{ "dispose",			FLCXObj::m_dispose,	 0, 0,	400 },
	{ nullptr, nullptr, 0, 0, 0 }
};

FLCXObject::FLCXObject(ObjectType ObjectType) :Object<FLCXObject>("FLCXObj") {
	_objType = ObjectType;
}

void FLCXObj::open(int type) {
	if (type == kXObj) {
		FLCXObject::initMethods(xlibMethods);
		FLCXObject *xobj = new FLCXObject(kXObj);
		g_lingo->exposeXObject(xlibName, xobj);
	} else if (type == kXtraObj) {
		// TODO - Implement Xtra
	}
}

void FLCXObj::close(int type) {
	if (type == kXObj) {
		FLCXObject::cleanupMethods();
		g_lingo->_globalvars[xlibName] = Datum();
	} else if (type == kXtraObj) {
		// TODO - Implement Xtra
	}
}

void FLCXObj::m_new(int nargs) {
	g_lingo->push(g_lingo->_state->me);
}

XOBJSTUB(FLCXObj::m_play, 0)
XOBJSTUB(FLCXObj::m_video, 0)
XOBJSTUB(FLCXObj::m_stretch, 0)
XOBJSTUB(FLCXObj::m_dispose, 0)

}
