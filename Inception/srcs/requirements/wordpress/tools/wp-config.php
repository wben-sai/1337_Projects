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
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */


// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('WP_DATABASE_NAME'));

/** MySQL database username */
define( 'DB_USER', getenv('WP_DATABASE_USER'));

/** MySQL database password */
define( 'DB_PASSWORD', getenv('WP_DATABASE_PASSWORD'));

/** MySQL hostname */
define( 'DB_HOST', getenv('WP_HOSTNAME'));

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
define( 'AUTH_KEY',         'h_jnlVe?$&]Oky!5z`dCYz|/.%7N()l#Lq7}[hMP$DF+V|05_=rLqrjWxuv &_v&' );
define( 'SECURE_AUTH_KEY',  'd0XO==Ddf?BpU3kl:+]B)Lc&wqj}eE.0y%Q26{UCqka,,.Aq]p*aTm%3V)%Lco{+' );
define( 'LOGGED_IN_KEY',    ']U9MdPH8Cp6aaT$$[ m5Th7arOme**rKJ>[(Hpn3hl@;tVkJ:HK:v<;d7f<RwUim' );
define( 'NONCE_KEY',        'Ng3))y)-y@5A/nbR>Nt0/.QC?3+7lc[&19|2@[=-4:L;a+mwy54KR`nZ9o$tpbiZ' );
define( 'AUTH_SALT',        'fixQb39{[@{z0oU&1cMPeM^(5z=U)r{Q3^_t/F7){2W}}|t}]A@:UGrTUNrj3hSb' );
define( 'SECURE_AUTH_SALT', 'h{(g,h7i<l.1_w#$3fLY)?Co#TT&9mf(yk>9|,5WFRm.&9?ZU^pgpVJJ~rs~_i-!' );
define( 'LOGGED_IN_SALT',   'V4~hSC4<@U$*mDTRZOv_o&S@.-<B??nu@GM53]KSV]vCPW3q7RV3}.K5y:K.!(]0' );
define( 'NONCE_SALT',       '{{NsT2wG)n8P<t_1Ng;01iR{CjS@OAC|vppxkp)|[<Qq=K7J0M!W&cX%0;!0([&-' );

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
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
