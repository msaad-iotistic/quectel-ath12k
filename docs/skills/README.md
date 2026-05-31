# Operator skills

Procedural knowledge accumulated while debugging the WCN7850 (ath12k-wifi7) AP-mode
firmware-crash and multi-client stability work on `mnvr`. These are not driver
patches — they're checklists, commands, and gotchas for the next operator (human
or AI assistant) who has to reproduce a workflow.

Each file is a self-contained skill. Read the one you need; they're cross-referenced
by name.

| Skill | When to use |
|---|---|
| [kernel-module-deploy.md](kernel-module-deploy.md) | Building + installing the out-of-tree `ath12k` / `ath12k_wifi7` modules on `mnvr` (kernel 7.0.0-15) |
| [ath12k-dmesg-signatures.md](ath12k-dmesg-signatures.md) | Recognising known ath12k log patterns: cosmetic noise, real bugs, and the cascade-triggers between them |
| [ap-l2l3-station-mismatch.md](ap-l2l3-station-mismatch.md) | Diagnosing the gap between `iw dev apN station dump` count (AP-side L2) and `nmcli connection show --active` count (client-side L3) |
| [wifi-clients-simulator-driving.md](wifi-clients-simulator-driving.md) | Operating the testrig's 31 USB wifi dongles via NetworkManager + `gen-nmcli-cmds.sh` — staggered vs simultaneous kickoff, etc. |

For tmate-bridge driving (the SSH transport, not ath12k-specific) see the user's
local skill at `~/.claude/skills/tmate-session/SKILL.md` — that one is generic
across projects.
