# $OpenBSD: Makefile,v 1.71 2022/02/13 16:38:31 rsadowski Exp $

USE_WXNEEDED =	Yes

COMMENT =	organizer for book/dvd/music collections

DISTNAME =	tellico-3.4.2
REVISION =	0

CATEGORIES =	x11

HOMEPAGE =	https://tellico-project.org

MAINTAINER =	Rafael Sadowski <rsadowski@openbsd.org>

# GPLv3
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} KF5Archive KF5Attica KF5Auth KF5AuthCore
WANTLIB += KF5Bookmarks KF5Cddb KF5Codecs KF5Completion KF5ConfigCore
WANTLIB += KF5ConfigGui KF5ConfigWidgets KF5CoreAddons KF5Crash
WANTLIB += KF5FileMetaData KF5GuiAddons KF5I18n KF5IconThemes
WANTLIB += KF5ItemModels KF5ItemViews KF5JobWidgets KF5KIOCore
WANTLIB += KF5KIOFileWidgets KF5KIOGui KF5KIOWidgets KF5NewStuff
WANTLIB += KF5NewStuffCore KF5Sane KF5Service KF5Solid KF5SonnetCore
WANTLIB += KF5SonnetUi KF5TextWidgets KF5Wallet KF5WidgetsAddons
WANTLIB += KF5WindowSystem KF5XmlGui Qt5Charts Qt5Concurrent Qt5Core
WANTLIB += Qt5DBus Qt5Gui Qt5Network Qt5Positioning Qt5PrintSupport
WANTLIB += Qt5Qml Qt5QmlModels Qt5Quick Qt5WebChannel Qt5WebEngineCore
WANTLIB += Qt5WebEngineWidgets Qt5Widgets Qt5Xml X11 c cdio exempi
WANTLIB += exslt iconv iso9660 m poppler poppler-qt5 tag xml2
WANTLIB += xslt yaz z

MASTER_SITES =	http://tellico-project.org/files/
EXTRACT_SUFX =	.tar.xz

MODULES +=	devel/kf5 \
		lang/python

BUILD_DEPENDS =	devel/gettext,-tools \
		devel/kf5/kdoctools

RUN_DEPENDS =	devel/desktop-file-utils \
		misc/shared-mime-info \
		devel/kf5/kdoctools \
		x11/gtk+3,-guic

LIB_DEPENDS =	audio/libcdio \
		audio/taglib \
		devel/kf5/attica \
		devel/kf5/karchive \
		devel/kf5/kbookmarks \
		devel/kf5/kcodecs \
		devel/kf5/kcompletion \
		devel/kf5/kconfig \
		devel/kf5/kconfigwidgets \
		devel/kf5/kcoreaddons \
		devel/kf5/kcrash \
		devel/kf5/kfilemetadata \
		devel/kf5/kguiaddons \
		devel/kf5/ki18n \
		devel/kf5/kiconthemes \
		devel/kf5/kio \
		devel/kf5/kitemmodels \
		devel/kf5/kitemviews \
		devel/kf5/kjobwidgets \
		devel/kf5/knewstuff \
		devel/kf5/kservice \
		devel/kf5/kwallet \
		devel/kf5/kwidgetsaddons \
		devel/kf5/kwindowsystem \
		devel/kf5/kxmlgui \
		devel/kf5/solid \
		devel/kf5/sonnet \
		net/yaz \
		print/poppler,-qt5 \
		textproc/exempi \
		textproc/libxml \
		textproc/libxslt \
		x11/kde-applications/libkcddb \
		x11/kde-applications/libksane \
		x11/qt5/qtdeclarative \
		x11/qt5/qtwebengine \
		x11/qt5/qtcharts

TEST_IS_INTERACTIVE =	X11

post-install:
	${MODPY_BIN} ${MODPY_LIBDIR}/compileall.py \
		${PREFIX}/share/tellico/data-sources/

.include <bsd.port.mk>
