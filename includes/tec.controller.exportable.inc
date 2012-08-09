<?php

/**
 * @file
 *   Technocrat Entity Controller Exportable class.
 */

/**
 * Technocrat Entity Controller class with exportable support.
 *
 * Export and import methods copied from from EntityAPIControllerExportable.
 */
class TecControllerExportable extends TecController {
  /**
   * Implements EntityAPIControllerInterface.
   */
  public function export($entity, $prefix = '') {
    $vars = get_object_vars($entity);
    unset($vars['is_new'], $vars['created'], $vars['modified'], $vars['status']);
    return entity_var_json_export($vars, $prefix);
  }

  /**
   * Implements EntityAPIControllerInterface.
   */
  public function import($export) {
    $vars = drupal_json_decode($export);
    if (is_array($vars)) {
      return $this->create($vars);
    }
    return FALSE;
  }
}
