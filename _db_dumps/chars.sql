-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jan 23, 2017 at 11:14 AM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `dnd_vault_e5`
--

-- --------------------------------------------------------

--
-- Table structure for table `chars_worlds`
--

CREATE TABLE IF NOT EXISTS `chars_worlds` (
  `id` int(2) NOT NULL AUTO_INCREMENT,
  `owner_id` int(11) NOT NULL,
  `universe_id` int(2) NOT NULL,
  `name` varchar(32) COLLATE utf16_unicode_ci NOT NULL,
  `privte` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf16 COLLATE=utf16_unicode_ci AUTO_INCREMENT=3 ;

--
-- Dumping data for table `chars_worlds`
--

INSERT INTO `chars_worlds` (`id`, `owner_id`, `universe_id`, `name`, `privte`) VALUES
(2, 1, 1, 'DnD - 5e', 0);

-- --------------------------------------------------------

--
-- Table structure for table `chars_world_universe`
--

CREATE TABLE IF NOT EXISTS `chars_world_universe` (
  `id` int(2) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf16 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `chars_world_universe`
--

INSERT INTO `chars_world_universe` (`id`, `name`) VALUES
(1, 'DnD');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
