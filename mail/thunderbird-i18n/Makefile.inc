# $OpenBSD: Makefile.inc,v 1.149 2022/02/16 05:13:37 landry Exp $

# keep in sync with www/mozilla/mozilla.port.mk
ONLY_FOR_ARCHS =	amd64 aarch64

PKG_ARCH =	*

FV =		91.6.1
V =		${FV:C/b.$//}
NAME =		thunderbird-i18n

CATEGORIES =	mail

HOMEPAGE =	https://wiki.mozilla.org/L10n:Home_Page

MAINTAINER =	Landry Breuil <landry@openbsd.org>

# Mozilla public license
PERMIT_PACKAGE =	Yes

MASTER_SITES =	https://ftp.mozilla.org/pub/mozilla.org/thunderbird/releases/${FV}/linux-x86_64/xpi/ \
		http://releases.mozilla.org/pub/mozilla.org/thunderbird/releases/${FV}/linux-x86_64/xpi/

LANGUAGES =	ar ast be bg br ca cs cy da de dsb el en-GB en-US es-AR es-ES et eu \
		fi fr fy-NL ga-IE gd gl he hr hsb hu hy-AM id is it ja ko lt nb-NO nl nn-NO \
		pl pt-BR pt-PT rm ro ru sk sl sq sr sv-SE tr uk vi \
		zh-CN zh-TW

BUILD_DEPENDS =	archivers/unzip
RUN_DEPENDS =	thunderbird->=${FV:S/b/beta/}:mail/mozilla-thunderbird

DIST_SUBDIR =	mozilla/${NAME}-${FV}
NO_BUILD =	Yes
NO_TEST =	Yes
EXTRACT_ONLY =

.for i in ${LANGUAGES}
SUPDISTFILES +=	$i.xpi
.endfor

PKGNAME =	${NAME}-$L-${FV:S/b/beta/}
COMMENT =	$L language pack for Thunderbird
DISTFILES =	$L.xpi

# use the same for all subpackages
PKGDIR =	${.CURDIR}/../pkg
PLIST =		${PKGDIR}/PLIST
DESCR =		${PKGDIR}/DESCR
CHECKSUM_FILE =	${.CURDIR}/../distinfo
MESSAGE=	${PKGDIR}/MESSAGE
SUBST_VARS =	V L

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/thunderbird/distribution/extensions
	${INSTALL_DATA} ${FULLDISTDIR}/$L.xpi ${PREFIX}/lib/thunderbird/distribution/extensions/langpack-$L@thunderbird.mozilla.org.xpi
