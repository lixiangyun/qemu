/*
 * QEMU save vm functions
 *
 * Copyright (c) 2003-2008 Fabrice Bellard
 * Copyright (c) 2009-2017 Red Hat Inc
 *
 * Authors:
 *  Juan Quintela <quintela@redhat.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef MIGRATION_SAVEVM_H
#define MIGRATION_SAVEVM_H

bool qemu_savevm_state_blocked(Error **errp);
void qemu_savevm_state_begin(QEMUFile *f);
void qemu_savevm_state_header(QEMUFile *f);
int qemu_savevm_state_iterate(QEMUFile *f, bool postcopy);
void qemu_savevm_state_cleanup(void);
void qemu_savevm_state_complete_postcopy(QEMUFile *f);
void qemu_savevm_state_complete_precopy(QEMUFile *f, bool iterable_only);
void qemu_savevm_state_pending(QEMUFile *f, uint64_t max_size,
                               uint64_t *res_non_postcopiable,
                               uint64_t *res_postcopiable);
void qemu_savevm_send_ping(QEMUFile *f, uint32_t value);
void qemu_savevm_send_open_return_path(QEMUFile *f);
int qemu_savevm_send_packaged(QEMUFile *f, const uint8_t *buf, size_t len);
void qemu_savevm_send_postcopy_advise(QEMUFile *f);
void qemu_savevm_send_postcopy_listen(QEMUFile *f);
void qemu_savevm_send_postcopy_run(QEMUFile *f);

void qemu_savevm_send_postcopy_ram_discard(QEMUFile *f, const char *name,
                                           uint16_t len,
                                           uint64_t *start_list,
                                           uint64_t *length_list);

int qemu_loadvm_state(QEMUFile *f);

#endif
