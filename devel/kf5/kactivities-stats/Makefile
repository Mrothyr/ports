# $OpenBSD: Makefile,v 1.17 2022/02/19 09:45:40 rsadowski Exp $

COMMENT =	statistics for the KDE Activity concept
DISTNAME =	kactivities-stats-${VERSION}

SHARED_LIBS =	KF5ActivitiesStats	10.0

WANTLIB += ${COMPILER_LIBCXX} KF5Activities KF5ConfigCore Qt5Core
WANTLIB += Qt5DBus Qt5Sql m

BUILD_DEPENDS =	devel/boost \
		x11/qt5/qtdeclarative \
		x11/qt5/qtquickcontrols

RUN_DEPENDS =	x11/qt5/qtquickcontrols

LIB_DEPENDS =	devel/kf5/kactivities>=${MODKF5_VERSION} \
		devel/kf5/kconfig>=${MODKF5_VERSION}

# For boost
CONFIGURE_ENV +=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include"

.include <bsd.port.mk>
