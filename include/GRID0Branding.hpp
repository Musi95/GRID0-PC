/*
 * GRID0 branding — single point of customization over upstream ZeroTier-One.
 *
 * ALL GRID0-specific product/binary/service/path names live in this file.
 * Upstream files reference these macros so that syncing future ZeroTier-One
 * updates stays a matter of resolving small, obvious conflicts instead of
 * re-doing a scattered string-replace across the codebase.
 *
 * Wire-protocol compatibility with stock ZeroTier is intentionally NOT
 * touched here: node identity format, planet, ports and VL1/VL2 are
 * unchanged, so stock ZeroTier peers interoperate with GRID0-PC builds.
 */

#ifndef GRID0_BRANDING_HPP
#define GRID0_BRANDING_HPP

/* Product name shown in version banners, help text and service UI */
#define GRID0_PRODUCT_NAME "GRID0"
#define GRID0_PRODUCT_NAME_LONG "GRID0 PC"

/* Output binary names produced by the build (one binary, three personalities) */
#define GRID0_BIN_ONE "grid0-pc"
#define GRID0_BIN_CLI "grid0-cli"
#define GRID0_BIN_IDTOOL "grid0-idtool"

/* Windows service names (see windows/ZeroTierOne/ZeroTierOneService.h) */
#define GRID0_SERVICE_NAME "GRID0PCService"
#define GRID0_SERVICE_DISPLAY_NAME "GRID0 PC"

/* Network automatically joined on first run (service/OneService.cpp) */
#define GRID0_DEFAULT_NETWORK_STR "8bd5124fd68185ec"
#define GRID0_DEFAULT_NETWORK_ID 0x8bd5124fd68185ecULL

/* Marker file (created in the home dir) recording that first-run auto-join ran */
#define GRID0_AUTOJOIN_MARKER "grid0-autojoin.done"

/* Runtime files in the home dir (written by the service, read by the CLI) */
#define GRID0_PORT_FILE "grid0-pc.port"
#define GRID0_PID_FILE "grid0-pc.pid"

/* Linux system user the service drops privileges to, if present */
#define GRID0_LINUX_USER "grid0-pc"

/*
 * Default home directory per platform.
 * Mirrors the upstream layout, just under GRID0 names.
 */
#ifdef __UNIX_LIKE__
#ifdef __APPLE__
/* /Library/... on Apple */
#define GRID0_DEFAULT_HOME "/Library/Application Support/GRID0/PC"
#elif defined(__BSD__)
/* BSD likes /var/db instead of /var/lib */
#define GRID0_DEFAULT_HOME "/var/db/grid0-pc"
#else
/* /var/lib for Linux and other *nix */
#define GRID0_DEFAULT_HOME "/var/lib/grid0-pc"
#endif
#elif defined(__WINDOWS__)
/* Built at runtime from CSIDL_COMMON_APPDATA; fallback if that lookup fails */
#define GRID0_HOME_SUBDIR "\\GRID0\\PC"
#define GRID0_HOME_FALLBACK "C:\\GRID0\\PC"
#else
/* Unknown platform */
#define GRID0_DEFAULT_HOME "/GRID0/PC"
#endif

#endif /* GRID0_BRANDING_HPP */
