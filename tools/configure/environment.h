/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the tools applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <qstringlist.h>

QT_BEGIN_NAMESPACE


enum Compiler {
    CC_UNKNOWN = 0,
    CC_BORLAND = 0x01,
    CC_MINGW   = 0x02,
    CC_INTEL   = 0x03,
    CC_MSVC2005 = 0x80,
    CC_MSVC2008 = 0x90,
    CC_MSVC2010 = 0xA0,
    CC_MSVC2012 = 0xB0,
    CC_MSVC2013 = 0xC0,
    CC_MSVC2015 = 0xD0
};

struct CompilerInfo;
class Environment
{
public:
    static Compiler detectCompiler();
    static QString detectQMakeSpec();
    static Compiler compilerFromQMakeSpec(const QString &qmakeSpec);
    static QString gccVersion();

    static int execute(QStringList arguments, const QStringList &additionalEnv, const QStringList &removeEnv);
    static QString execute(const QString &command, int *returnCode = 0);
    static bool cpdir(const QString &srcDir, const QString &destDir);
    static bool rmdir(const QString &name);

    static QString findFileInPaths(const QString &fileName, const QStringList &paths);
    static QStringList path();

    static QString detectDirectXSdk();
    static QStringList headerPaths(Compiler compiler);
    static QStringList libraryPaths(Compiler compiler);

private:
    static Compiler detectedCompiler;

    static CompilerInfo *compilerInfo(Compiler compiler);
};


QT_END_NAMESPACE
