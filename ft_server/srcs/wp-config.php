<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wpdb' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'root' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '>N{S64c#4?bna*Gse1+zsw#N||s[R5hvVzBrbs&Dc[OO)O^`V;Al<g(~!Sfep*M?' );
define( 'SECURE_AUTH_KEY',  'afDHf:PvwJ+Mzh[1fZ4_*jkUIs#K@Eo=jW<Jh*[40O6]hyFpv<;`~eURs<f1,6N6' );
define( 'LOGGED_IN_KEY',    'aWy[*T@ZLXG}(~x13gmnw*XnA.Sn~j~Z3jaLUZM}*?c8zKZA.3PR0MAnLR4sYD1t' );
define( 'NONCE_KEY',        'Sc{9)K3TOluV4ocw!gPn!qe(+j_/TRCU=if|Jxum)F(]3~@j>w8dFA-Bsg 8?vBr' );
define( 'AUTH_SALT',        'G*Q0HaM{mIDNzET?2vBT(nC=(<O9Qy<`]?n;.#58z}1kefHuT@?&^S)LEquNO4^@' );
define( 'SECURE_AUTH_SALT', '*ie@a~,vyURQVG[Qib=,zy/@l=R.i5|?Is~(U!_;3~YjLUT-sea/Tqsg0ioO/PQi' );
define( 'LOGGED_IN_SALT',   'NCUf<pTbU()#6I9gt-uSVZ1L~ cn)SNbLKlTtm5|NO^EJR;lr3:6T#<aK^|J@bgk' );
define( 'NONCE_SALT',       'Nx0uD<d<x4wx@b *_b:OAC?f*aDp;,f8:Zy*6w*Xtz6=NWW}gikP!sd?Ba1(hqUq' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );