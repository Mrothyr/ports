# $OpenBSD: Makefile,v 1.12 2021/11/15 21:23:31 rsadowski Exp $

QT5NAME =		QtQuickControls
COMMENT-main =		Qt Quick based UI controls

REVISION-main =		0
REVISION-examples =	0

MULTI_PACKAGES =	-main -examples

WANTLIB += ${COMPILER_LIBCXX} GL Qt5Core Qt5Gui Qt5Network Qt5Qml
WANTLIB += Qt5QmlModels Qt5Quick Qt5Widgets m


LIB_DEPENDS =		x11/qt5/qtdeclarative>=${QT5_VERSION},<${QT5_NEXT_VERSION}

FLAVORS =		debug

.include <bsd.port.mk>
