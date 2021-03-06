DESCRIPTION = "Utils for blindscan"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

PACKAGES = "vuplus-blindscan-dvbs-utils-${MACHINE} vuplus-blindscan-dvbc-utils-${MACHINE}"

PROVIDES += "virtual/blindscan-dvbs virtual/blindscan-dvbc"
RPROVIDES_vuplus-blindscan-dvbs-utils-${MACHINE} += "virtual/blindscan-dvbs"
RPROVIDES_vuplus-blindscan-dvbc-utils-${MACHINE} += "virtual/blindscan-dvbc"

PV = "4.2"

SRC_URI = "http://archive.vuplus.com/download/utils/vuplus-blindscan-utils-${PV}.tar.gz"

SRC_URI[md5sum] = "93f74f70612b209641b5673ad7c523dc"
SRC_URI[sha256sum] = "cb3af3cdecedae47f0511a4997124c897e43aaf8126609fa654447637b8a58f4"

S = "${WORKDIR}/blindscan-utils"

PLUGABLE_MODEL_BLINDSCAN = " \
        tda1002x \
        vuplus_blindscan \
        vuplus_6211_blindscan \
        vuplus_6222_blindscan \
        ssh108 \
        ssh108_t2_scan \
        tt3l10 \
        tt3l10_t2_scan \
"

do_install() {
	install -d "${D}/${bindir}"
	install -m 0755 "${S}/tda1002x" "${D}/${bindir}"
}

do_install_vuuno() {
        install -d "${D}/${bindir}"
        for f in ${PLUGABLE_MODEL_BLINDSCAN}; do
                install -m 0755 "${S}/$f" "${D}/${bindir}"
        done
}

do_install_vuultimo() {
        install -d "${D}/${bindir}"
        for f in ${PLUGABLE_MODEL_BLINDSCAN}; do
                install -m 0755 "${S}/$f" "${D}/${bindir}"
        done
}

do_install_vuduo2() {
        install -d "${D}/${bindir}"
        for f in ${PLUGABLE_MODEL_BLINDSCAN}; do
                install -m 0755 "${S}/$f" "${D}/${bindir}"
        done
}

do_install_vusolose() {
        install -d "${D}/${bindir}"
        for f in ${PLUGABLE_MODEL_BLINDSCAN}; do
                install -m 0755 "${S}/$f" "${D}/${bindir}"
        done
}

do_install_vusolo2() {
	install -d "${D}/${bindir}"
	install -m 0755 "${S}/tda1002x" "${D}/${bindir}"
	install -m 0755 "${S}/vuplus_bcm7346_blindscan" "${D}/${bindir}"
}

FILES_vuplus-blindscan-dvbs-utils-${MACHINE} = "\
	${bindir}/vuplus_blindscan \
	${bindir}/vuplus_6211_blindscan \
	${bindir}/vuplus_6222_blindscan \
	${bindir}/vuplus_bcm7346_blindscan \
	"

FILES_vuplus-blindscan-dvbc-utils-${MACHINE} = "\
	${bindir}/tda1002x \
	${bindir}/ssh108 \
	${bindir}/ssh108_t2_scan \
	${bindir}/tt3l10 \
	${bindir}/tt3l10_t2_scan \
	"

INHIBIT_PACKAGE_STRIP = "1"

PACKAGE_ARCH := "${MACHINE_ARCH}"

