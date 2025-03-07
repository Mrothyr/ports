# $OpenBSD: Makefile,v 1.21 2022/01/05 08:02:53 rsadowski Exp $

COMMENT =	periodic table of elements
DISTNAME =	kalzium-${VERSION}
CATEGORIES =	education math

HOMEPAGE =	https://edu.kde.org/kalzium/

SHARED_LIBS +=  science                   2.0 # 5.0

WANTLIB += ${COMPILER_LIBCXX} KF5Auth KF5AuthCore KF5Codecs KF5Completion
WANTLIB += KF5ConfigCore KF5ConfigGui KF5ConfigWidgets KF5CoreAddons
WANTLIB += KF5I18n KF5ItemViews KF5JobWidgets KF5KIOCore KF5KIOGui
WANTLIB += KF5KIOWidgets KF5Plotting KF5Service KF5Solid KF5SonnetUi
WANTLIB += KF5TextWidgets KF5UnitConversion KF5WidgetsAddons KF5WindowSystem
WANTLIB += KF5XmlGui Qt5Concurrent Qt5Core Qt5DBus Qt5Gui Qt5Network
WANTLIB += Qt5Script Qt5Svg Qt5Widgets Qt5Xml X11 c m openbabel

MODKDE5_DESKTOP_FILE = yes
MODKDE5_ICON_CACHE = yes
MODKDE5_TRANSLATIONS = yes
MODKF5_I18N_CONFLICT = yes
MODKF5_L10N_CONFLICT = yes
MODKDE5_DOCS = yes

MODULES +=	lang/python \
		lang/ocaml

MODPY_RUNDEP=	No

BUILD_DEPENDS =	devel/kf5/karchive \
		devel/kf5/kbookmarks \
		devel/kf5/kparts \
		devel/kf5/solid \
		math/eigen3

RUN_DEPENDS =	devel/kf5/karchive \
		devel/kf5/kbookmarks \
		devel/kf5/kparts \
		devel/kf5/solid

LIB_DEPENDS =	devel/kf5/kauth \
		devel/kf5/kcodecs \
		devel/kf5/kcompletion \
		devel/kf5/kconfig \
		devel/kf5/kconfigwidgets \
		devel/kf5/kcoreaddons \
		devel/kf5/ki18n \
		devel/kf5/kio \
		devel/kf5/kjobwidgets \
		devel/kf5/kplotting \
		devel/kf5/ktextwidgets \
		devel/kf5/kunitconversion \
		devel/kf5/kwidgetsaddons \
		devel/kf5/sonnet \
		misc/openbabel \
		x11/qt5/qtscript \
		x11/qt5/qtsvg

.include <bsd.port.mk>
