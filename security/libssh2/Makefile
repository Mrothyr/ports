# $OpenBSD: Makefile,v 1.24 2021/11/13 19:36:14 tb Exp $

COMMENT =		library implementing the SSH2 protocol

DISTNAME =		libssh2-1.10.0
CATEGORIES =		security
SHARED_LIBS +=		ssh2	10.0	# .1.1
REVISION =		0

HOMEPAGE =		https://www.libssh2.org/

MAINTAINER =		Benoit Lecocq <benoit@openbsd.org>

# libssh2: BSD License
# libssh2 Documentation: Open Publication License
PERMIT_PACKAGE =	Yes

WANTLIB =		crypto ssl z

MASTER_SITES =		https://www.libssh2.org/download/

CONFIGURE_STYLE =	gnu

CFLAGS +=		-DHAVE_OPAQUE_STRUCTS=1

# The second test will only pass if public key auth is configured for ${USER}
TEST_IS_INTERACTIVE = Yes
TEST_FLAGS="USER=${USER}"

.include <bsd.port.mk>
