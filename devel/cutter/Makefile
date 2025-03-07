# $OpenBSD: Makefile,v 1.12 2022/02/20 15:37:07 rsadowski Exp $

COMMENT =	RE platform powered by radare2

GH_ACCOUNT =	radareorg
GH_PROJECT =	cutter
GH_TAGNAME =	v1.12.0
REVISION =	1

CATEGORIES =	devel

HOMEPAGE =	https://cutter.re/

MAINTAINER =	Jasper Lievisse Adriaanse <jasper@openbsd.org>

# GPLv3
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} ${MODPY_WANTLIB}
WANTLIB += KF5SyntaxHighlighting Qt5Core Qt5Gui Qt5Network Qt5Svg
WANTLIB += Qt5Widgets c capstone cdt cgraph crypto gvc m ssl z
WANTLIB += zip

MODULES =	devel/cmake \
		lang/python \
		x11/qt5

BUILD_DEPENDS =	${RUN_DEPENDS}
RUN_DEPENDS =	devel/radare2/main>=4.5.1
LIB_DEPENDS =	archivers/libzip \
		devel/capstone/main \
		devel/kf5/syntax-highlighting \
		math/graphviz \
		x11/qt5/qtsvg

WRKSRC =	${WRKDIST}/src

# XXX: Python-based plugins don't work yet, this needs
# CUTTER_ENABLE_PYTHON_BINDINGS which requires (unported) Shiboken2.
CONFIGURE_ARGS =-DCUTTER_ENABLE_GRAPHVIZ=ON \
		-DCUTTER_ENABLE_KSYNTAXHIGHLIGHTING=ON \
		-DCUTTER_ENABLE_PYTHON=ON \
		-DCUTTER_ENABLE_CRASH_REPORTS=OFF \
		-DCUTTER_USE_BUNDLED_RADARE2=OFF

NO_TEST =	Yes

CONFIGURE_ARGS +=	-DCMAKE_C_FLAGS="${CFLAGS} -I${LOCALBASE}/include/KF5" \
                   	-DCMAKE_CXX_FLAGS="${CXXFLAGS} -I${LOCALBASE}/include/KF5"

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/Cutter ${PREFIX}/bin/cutter

.include <bsd.port.mk>
