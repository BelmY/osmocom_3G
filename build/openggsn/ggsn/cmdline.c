/*
  File autogenerated by gengetopt version 2.22.6
  generated with the following command:
  gengetopt -i cmdline.ggo --conf-parser 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include <getopt.h>

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "";

const char *gengetopt_args_info_usage = "Usage: " CMDLINE_PARSER_PACKAGE " [OPTIONS]...";

const char *gengetopt_args_info_versiontext = "";

const char *gengetopt_args_info_description = "";

const char *gengetopt_args_info_help[] = {
  "  -h, --help             Print help and exit",
  "  -V, --version          Print version and exit",
  "  -f, --fg               Run in foreground  (default=off)",
  "  -d, --debug            Run in debug mode  (default=off)",
  "  -c, --conf=STRING      Read configuration file  (default=`/etc/ggsn.conf')",
  "      --pidfile=STRING   Filename of process id file\n                           (default=`/var/run/ggsn.pid')",
  "      --statedir=STRING  Directory of nonvolatile data\n                           (default=`/var/lib/ggsn/')",
  "  -l, --listen=STRING    Local interface",
  "  -n, --net=STRING       Network  (default=`192.168.0.0/24')",
  "      --ipup=STRING      Script to run after link-up",
  "      --ipdown=STRING    Script to run after link-down",
  "      --dynip=STRING     Dynamic IP address pool",
  "      --statip=STRING    Static IP address pool",
  "      --pcodns1=STRING   PCO DNS Server 1  (default=`0.0.0.0')",
  "      --pcodns2=STRING   PCO DNS Server 2  (default=`0.0.0.0')",
  "      --timelimit=INT    Exit after timelimit seconds  (default=`0')",
  "  -a, --apn=STRING       Access point name  (default=`internet')",
  "  -q, --qos=INT          Requested quality of service  (default=`0x0b921f')",
  "      --logfile=STRING   Logfile for errors",
  "      --loglevel=STRING  Global log ldevel  (default=`error')",
  "  -g, --gtp-linux        GTP linux kernel support  (default=off)",
    0
};

typedef enum {ARG_NO
  , ARG_FLAG
  , ARG_STRING
  , ARG_INT
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);

struct line_list
{
  char * string_arg;
  struct line_list * next;
};

static struct line_list *cmd_line_list = 0;
static struct line_list *cmd_line_list_tmp = 0;

static void
free_cmd_list(void)
{
  /* free the list of a previous call */
  if (cmd_line_list)
    {
      while (cmd_line_list) {
        cmd_line_list_tmp = cmd_line_list;
        cmd_line_list = cmd_line_list->next;
        free (cmd_line_list_tmp->string_arg);
        free (cmd_line_list_tmp);
      }
    }
}


static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->fg_given = 0 ;
  args_info->debug_given = 0 ;
  args_info->conf_given = 0 ;
  args_info->pidfile_given = 0 ;
  args_info->statedir_given = 0 ;
  args_info->listen_given = 0 ;
  args_info->net_given = 0 ;
  args_info->ipup_given = 0 ;
  args_info->ipdown_given = 0 ;
  args_info->dynip_given = 0 ;
  args_info->statip_given = 0 ;
  args_info->pcodns1_given = 0 ;
  args_info->pcodns2_given = 0 ;
  args_info->timelimit_given = 0 ;
  args_info->apn_given = 0 ;
  args_info->qos_given = 0 ;
  args_info->logfile_given = 0 ;
  args_info->loglevel_given = 0 ;
  args_info->gtp_linux_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->fg_flag = 0;
  args_info->debug_flag = 0;
  args_info->conf_arg = gengetopt_strdup ("/etc/ggsn.conf");
  args_info->conf_orig = NULL;
  args_info->pidfile_arg = gengetopt_strdup ("/var/run/ggsn.pid");
  args_info->pidfile_orig = NULL;
  args_info->statedir_arg = gengetopt_strdup ("/var/lib/ggsn/");
  args_info->statedir_orig = NULL;
  args_info->listen_arg = NULL;
  args_info->listen_orig = NULL;
  args_info->net_arg = gengetopt_strdup ("192.168.0.0/24");
  args_info->net_orig = NULL;
  args_info->ipup_arg = NULL;
  args_info->ipup_orig = NULL;
  args_info->ipdown_arg = NULL;
  args_info->ipdown_orig = NULL;
  args_info->dynip_arg = NULL;
  args_info->dynip_orig = NULL;
  args_info->statip_arg = NULL;
  args_info->statip_orig = NULL;
  args_info->pcodns1_arg = gengetopt_strdup ("0.0.0.0");
  args_info->pcodns1_orig = NULL;
  args_info->pcodns2_arg = gengetopt_strdup ("0.0.0.0");
  args_info->pcodns2_orig = NULL;
  args_info->timelimit_arg = 0;
  args_info->timelimit_orig = NULL;
  args_info->apn_arg = gengetopt_strdup ("internet");
  args_info->apn_orig = NULL;
  args_info->qos_arg = 0x0b921f;
  args_info->qos_orig = NULL;
  args_info->logfile_arg = NULL;
  args_info->logfile_orig = NULL;
  args_info->loglevel_arg = gengetopt_strdup ("error");
  args_info->loglevel_orig = NULL;
  args_info->gtp_linux_flag = 0;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->fg_help = gengetopt_args_info_help[2] ;
  args_info->debug_help = gengetopt_args_info_help[3] ;
  args_info->conf_help = gengetopt_args_info_help[4] ;
  args_info->pidfile_help = gengetopt_args_info_help[5] ;
  args_info->statedir_help = gengetopt_args_info_help[6] ;
  args_info->listen_help = gengetopt_args_info_help[7] ;
  args_info->net_help = gengetopt_args_info_help[8] ;
  args_info->ipup_help = gengetopt_args_info_help[9] ;
  args_info->ipdown_help = gengetopt_args_info_help[10] ;
  args_info->dynip_help = gengetopt_args_info_help[11] ;
  args_info->statip_help = gengetopt_args_info_help[12] ;
  args_info->pcodns1_help = gengetopt_args_info_help[13] ;
  args_info->pcodns2_help = gengetopt_args_info_help[14] ;
  args_info->timelimit_help = gengetopt_args_info_help[15] ;
  args_info->apn_help = gengetopt_args_info_help[16] ;
  args_info->qos_help = gengetopt_args_info_help[17] ;
  args_info->logfile_help = gengetopt_args_info_help[18] ;
  args_info->loglevel_help = gengetopt_args_info_help[19] ;
  args_info->gtp_linux_help = gengetopt_args_info_help[20] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CMDLINE_PARSER_PACKAGE_NAME) ? CMDLINE_PARSER_PACKAGE_NAME : CMDLINE_PARSER_PACKAGE),
     CMDLINE_PARSER_VERSION);

  if (strlen(gengetopt_args_info_versiontext) > 0)
    printf("\n%s\n", gengetopt_args_info_versiontext);
}

static void print_help_common(void) {
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  if (strlen(gengetopt_args_info_usage) > 0)
    printf("\n%s\n", gengetopt_args_info_usage);

  printf("\n");

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n\n", gengetopt_args_info_description);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{

  free_string_field (&(args_info->conf_arg));
  free_string_field (&(args_info->conf_orig));
  free_string_field (&(args_info->pidfile_arg));
  free_string_field (&(args_info->pidfile_orig));
  free_string_field (&(args_info->statedir_arg));
  free_string_field (&(args_info->statedir_orig));
  free_string_field (&(args_info->listen_arg));
  free_string_field (&(args_info->listen_orig));
  free_string_field (&(args_info->net_arg));
  free_string_field (&(args_info->net_orig));
  free_string_field (&(args_info->ipup_arg));
  free_string_field (&(args_info->ipup_orig));
  free_string_field (&(args_info->ipdown_arg));
  free_string_field (&(args_info->ipdown_orig));
  free_string_field (&(args_info->dynip_arg));
  free_string_field (&(args_info->dynip_orig));
  free_string_field (&(args_info->statip_arg));
  free_string_field (&(args_info->statip_orig));
  free_string_field (&(args_info->pcodns1_arg));
  free_string_field (&(args_info->pcodns1_orig));
  free_string_field (&(args_info->pcodns2_arg));
  free_string_field (&(args_info->pcodns2_orig));
  free_string_field (&(args_info->timelimit_orig));
  free_string_field (&(args_info->apn_arg));
  free_string_field (&(args_info->apn_orig));
  free_string_field (&(args_info->qos_orig));
  free_string_field (&(args_info->logfile_arg));
  free_string_field (&(args_info->logfile_orig));
  free_string_field (&(args_info->loglevel_arg));
  free_string_field (&(args_info->loglevel_orig));
  
  

  clear_given (args_info);
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  FIX_UNUSED (values);
  if (arg) {
    fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->fg_given)
    write_into_file(outfile, "fg", 0, 0 );
  if (args_info->debug_given)
    write_into_file(outfile, "debug", 0, 0 );
  if (args_info->conf_given)
    write_into_file(outfile, "conf", args_info->conf_orig, 0);
  if (args_info->pidfile_given)
    write_into_file(outfile, "pidfile", args_info->pidfile_orig, 0);
  if (args_info->statedir_given)
    write_into_file(outfile, "statedir", args_info->statedir_orig, 0);
  if (args_info->listen_given)
    write_into_file(outfile, "listen", args_info->listen_orig, 0);
  if (args_info->net_given)
    write_into_file(outfile, "net", args_info->net_orig, 0);
  if (args_info->ipup_given)
    write_into_file(outfile, "ipup", args_info->ipup_orig, 0);
  if (args_info->ipdown_given)
    write_into_file(outfile, "ipdown", args_info->ipdown_orig, 0);
  if (args_info->dynip_given)
    write_into_file(outfile, "dynip", args_info->dynip_orig, 0);
  if (args_info->statip_given)
    write_into_file(outfile, "statip", args_info->statip_orig, 0);
  if (args_info->pcodns1_given)
    write_into_file(outfile, "pcodns1", args_info->pcodns1_orig, 0);
  if (args_info->pcodns2_given)
    write_into_file(outfile, "pcodns2", args_info->pcodns2_orig, 0);
  if (args_info->timelimit_given)
    write_into_file(outfile, "timelimit", args_info->timelimit_orig, 0);
  if (args_info->apn_given)
    write_into_file(outfile, "apn", args_info->apn_orig, 0);
  if (args_info->qos_given)
    write_into_file(outfile, "qos", args_info->qos_orig, 0);
  if (args_info->logfile_given)
    write_into_file(outfile, "logfile", args_info->logfile_orig, 0);
  if (args_info->loglevel_given)
    write_into_file(outfile, "loglevel", args_info->loglevel_orig, 0);
  if (args_info->gtp_linux_given)
    write_into_file(outfile, "gtp-linux", 0, 0 );
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char **argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char **argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  FIX_UNUSED (args_info);
  FIX_UNUSED (prog_name);
  return EXIT_SUCCESS;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  char **string_field;
  FIX_UNUSED (field);

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  FIX_UNUSED (default_value);
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_FLAG:
    *((int *)field) = !*((int *)field);
    break;
  case ARG_INT:
    if (val) *((int *)field) = strtol (val, &stop_char, 0);
    break;
  case ARG_STRING:
    if (val) {
      string_field = (char **)field;
      if (!no_free && *string_field)
        free (*string_field); /* free previous string */
      *string_field = gengetopt_strdup (val);
    }
    break;
  default:
    break;
  };

  /* check numeric conversion */
  switch(arg_type) {
  case ARG_INT:
    if (val && !(stop_char && *stop_char == '\0')) {
      fprintf(stderr, "%s: invalid numeric value: %s\n", package_name, val);
      return 1; /* failure */
    }
    break;
  default:
    ;
  };

  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
  case ARG_FLAG:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


int
cmdline_parser_internal (
  int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error_occurred = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "fg",	0, NULL, 'f' },
        { "debug",	0, NULL, 'd' },
        { "conf",	1, NULL, 'c' },
        { "pidfile",	1, NULL, 0 },
        { "statedir",	1, NULL, 0 },
        { "listen",	1, NULL, 'l' },
        { "net",	1, NULL, 'n' },
        { "ipup",	1, NULL, 0 },
        { "ipdown",	1, NULL, 0 },
        { "dynip",	1, NULL, 0 },
        { "statip",	1, NULL, 0 },
        { "pcodns1",	1, NULL, 0 },
        { "pcodns2",	1, NULL, 0 },
        { "timelimit",	1, NULL, 0 },
        { "apn",	1, NULL, 'a' },
        { "qos",	1, NULL, 'q' },
        { "logfile",	1, NULL, 0 },
        { "loglevel",	1, NULL, 0 },
        { "gtp-linux",	0, NULL, 'g' },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "hVfdc:l:n:a:q:g", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'f':	/* Run in foreground.  */
        
        
          if (update_arg((void *)&(args_info->fg_flag), 0, &(args_info->fg_given),
              &(local_args_info.fg_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "fg", 'f',
              additional_error))
            goto failure;
        
          break;
        case 'd':	/* Run in debug mode.  */
        
        
          if (update_arg((void *)&(args_info->debug_flag), 0, &(args_info->debug_given),
              &(local_args_info.debug_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "debug", 'd',
              additional_error))
            goto failure;
        
          break;
        case 'c':	/* Read configuration file.  */
        
        
          if (update_arg( (void *)&(args_info->conf_arg), 
               &(args_info->conf_orig), &(args_info->conf_given),
              &(local_args_info.conf_given), optarg, 0, "/etc/ggsn.conf", ARG_STRING,
              check_ambiguity, override, 0, 0,
              "conf", 'c',
              additional_error))
            goto failure;
        
          break;
        case 'l':	/* Local interface.  */
        
        
          if (update_arg( (void *)&(args_info->listen_arg), 
               &(args_info->listen_orig), &(args_info->listen_given),
              &(local_args_info.listen_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "listen", 'l',
              additional_error))
            goto failure;
        
          break;
        case 'n':	/* Network.  */
        
        
          if (update_arg( (void *)&(args_info->net_arg), 
               &(args_info->net_orig), &(args_info->net_given),
              &(local_args_info.net_given), optarg, 0, "192.168.0.0/24", ARG_STRING,
              check_ambiguity, override, 0, 0,
              "net", 'n',
              additional_error))
            goto failure;
        
          break;
        case 'a':	/* Access point name.  */
        
        
          if (update_arg( (void *)&(args_info->apn_arg), 
               &(args_info->apn_orig), &(args_info->apn_given),
              &(local_args_info.apn_given), optarg, 0, "internet", ARG_STRING,
              check_ambiguity, override, 0, 0,
              "apn", 'a',
              additional_error))
            goto failure;
        
          break;
        case 'q':	/* Requested quality of service.  */
        
        
          if (update_arg( (void *)&(args_info->qos_arg), 
               &(args_info->qos_orig), &(args_info->qos_given),
              &(local_args_info.qos_given), optarg, 0, "0x0b921f", ARG_INT,
              check_ambiguity, override, 0, 0,
              "qos", 'q',
              additional_error))
            goto failure;
        
          break;
        case 'g':	/* GTP linux kernel support.  */
        
        
          if (update_arg((void *)&(args_info->gtp_linux_flag), 0, &(args_info->gtp_linux_given),
              &(local_args_info.gtp_linux_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "gtp-linux", 'g',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          /* Filename of process id file.  */
          if (strcmp (long_options[option_index].name, "pidfile") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->pidfile_arg), 
                 &(args_info->pidfile_orig), &(args_info->pidfile_given),
                &(local_args_info.pidfile_given), optarg, 0, "/var/run/ggsn.pid", ARG_STRING,
                check_ambiguity, override, 0, 0,
                "pidfile", '-',
                additional_error))
              goto failure;
          
          }
          /* Directory of nonvolatile data.  */
          else if (strcmp (long_options[option_index].name, "statedir") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->statedir_arg), 
                 &(args_info->statedir_orig), &(args_info->statedir_given),
                &(local_args_info.statedir_given), optarg, 0, "/var/lib/ggsn/", ARG_STRING,
                check_ambiguity, override, 0, 0,
                "statedir", '-',
                additional_error))
              goto failure;
          
          }
          /* Script to run after link-up.  */
          else if (strcmp (long_options[option_index].name, "ipup") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->ipup_arg), 
                 &(args_info->ipup_orig), &(args_info->ipup_given),
                &(local_args_info.ipup_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "ipup", '-',
                additional_error))
              goto failure;
          
          }
          /* Script to run after link-down.  */
          else if (strcmp (long_options[option_index].name, "ipdown") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->ipdown_arg), 
                 &(args_info->ipdown_orig), &(args_info->ipdown_given),
                &(local_args_info.ipdown_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "ipdown", '-',
                additional_error))
              goto failure;
          
          }
          /* Dynamic IP address pool.  */
          else if (strcmp (long_options[option_index].name, "dynip") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->dynip_arg), 
                 &(args_info->dynip_orig), &(args_info->dynip_given),
                &(local_args_info.dynip_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "dynip", '-',
                additional_error))
              goto failure;
          
          }
          /* Static IP address pool.  */
          else if (strcmp (long_options[option_index].name, "statip") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->statip_arg), 
                 &(args_info->statip_orig), &(args_info->statip_given),
                &(local_args_info.statip_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "statip", '-',
                additional_error))
              goto failure;
          
          }
          /* PCO DNS Server 1.  */
          else if (strcmp (long_options[option_index].name, "pcodns1") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->pcodns1_arg), 
                 &(args_info->pcodns1_orig), &(args_info->pcodns1_given),
                &(local_args_info.pcodns1_given), optarg, 0, "0.0.0.0", ARG_STRING,
                check_ambiguity, override, 0, 0,
                "pcodns1", '-',
                additional_error))
              goto failure;
          
          }
          /* PCO DNS Server 2.  */
          else if (strcmp (long_options[option_index].name, "pcodns2") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->pcodns2_arg), 
                 &(args_info->pcodns2_orig), &(args_info->pcodns2_given),
                &(local_args_info.pcodns2_given), optarg, 0, "0.0.0.0", ARG_STRING,
                check_ambiguity, override, 0, 0,
                "pcodns2", '-',
                additional_error))
              goto failure;
          
          }
          /* Exit after timelimit seconds.  */
          else if (strcmp (long_options[option_index].name, "timelimit") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->timelimit_arg), 
                 &(args_info->timelimit_orig), &(args_info->timelimit_given),
                &(local_args_info.timelimit_given), optarg, 0, "0", ARG_INT,
                check_ambiguity, override, 0, 0,
                "timelimit", '-',
                additional_error))
              goto failure;
          
          }
          /* Logfile for errors.  */
          else if (strcmp (long_options[option_index].name, "logfile") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->logfile_arg), 
                 &(args_info->logfile_orig), &(args_info->logfile_given),
                &(local_args_info.logfile_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "logfile", '-',
                additional_error))
              goto failure;
          
          }
          /* Global log ldevel.  */
          else if (strcmp (long_options[option_index].name, "loglevel") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->loglevel_arg), 
                 &(args_info->loglevel_orig), &(args_info->loglevel_given),
                &(local_args_info.loglevel_given), optarg, 0, "error", ARG_STRING,
                check_ambiguity, override, 0, 0,
                "loglevel", '-',
                additional_error))
              goto failure;
          
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */




  cmdline_parser_release (&local_args_info);

  if ( error_occurred )
    return (EXIT_FAILURE);

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}

#ifndef CONFIG_FILE_LINE_SIZE
#define CONFIG_FILE_LINE_SIZE 2048
#endif
#define ADDITIONAL_ERROR " in configuration file "

#define CONFIG_FILE_LINE_BUFFER_SIZE (CONFIG_FILE_LINE_SIZE+3)
/* 3 is for "--" and "=" */

static int
_cmdline_parser_configfile (const char *filename, int *my_argc)
{
  FILE* file;
  char my_argv[CONFIG_FILE_LINE_BUFFER_SIZE+1];
  char linebuf[CONFIG_FILE_LINE_SIZE];
  int line_num = 0;
  int result = 0, equal;
  char *fopt, *farg;
  char *str_index;
  size_t len, next_token;
  char delimiter;

  if ((file = fopen(filename, "r")) == 0)
    {
      fprintf (stderr, "%s: Error opening configuration file '%s'\n",
               CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  while ((fgets(linebuf, CONFIG_FILE_LINE_SIZE, file)) != 0)
    {
      ++line_num;
      my_argv[0] = '\0';
      len = strlen(linebuf);
      if (len > (CONFIG_FILE_LINE_BUFFER_SIZE-1))
        {
          fprintf (stderr, "%s:%s:%d: Line too long in configuration file\n",
                   CMDLINE_PARSER_PACKAGE, filename, line_num);
          result = EXIT_FAILURE;
          break;
        }

      /* find first non-whitespace character in the line */
      next_token = strspn (linebuf, " \t\r\n");
      str_index  = linebuf + next_token;

      if ( str_index[0] == '\0' || str_index[0] == '#')
        continue; /* empty line or comment line is skipped */

      fopt = str_index;

      /* truncate fopt at the end of the first non-valid character */
      next_token = strcspn (fopt, " \t\r\n=");

      if (fopt[next_token] == '\0') /* the line is over */
        {
          farg  = 0;
          equal = 0;
          goto noarg;
        }

      /* remember if equal sign is present */
      equal = (fopt[next_token] == '=');
      fopt[next_token++] = '\0';

      /* advance pointers to the next token after the end of fopt */
      next_token += strspn (fopt + next_token, " \t\r\n");

      /* check for the presence of equal sign, and if so, skip it */
      if ( !equal )
        if ((equal = (fopt[next_token] == '=')))
          {
            next_token++;
            next_token += strspn (fopt + next_token, " \t\r\n");
          }
      str_index  += next_token;

      /* find argument */
      farg = str_index;
      if ( farg[0] == '\"' || farg[0] == '\'' )
        { /* quoted argument */
          str_index = strchr (++farg, str_index[0] ); /* skip opening quote */
          if (! str_index)
            {
              fprintf
                (stderr,
                 "%s:%s:%d: unterminated string in configuration file\n",
                 CMDLINE_PARSER_PACKAGE, filename, line_num);
              result = EXIT_FAILURE;
              break;
            }
        }
      else
        { /* read up the remaining part up to a delimiter */
          next_token = strcspn (farg, " \t\r\n#\'\"");
          str_index += next_token;
        }

      /* truncate farg at the delimiter and store it for further check */
      delimiter = *str_index, *str_index++ = '\0';

      /* everything but comment is illegal at the end of line */
      if (delimiter != '\0' && delimiter != '#')
        {
          str_index += strspn(str_index, " \t\r\n");
          if (*str_index != '\0' && *str_index != '#')
            {
              fprintf
                (stderr,
                 "%s:%s:%d: malformed string in configuration file\n",
                 CMDLINE_PARSER_PACKAGE, filename, line_num);
              result = EXIT_FAILURE;
              break;
            }
        }

    noarg:
      if (!strcmp(fopt,"include")) {
        if (farg && *farg) {
          result = _cmdline_parser_configfile(farg, my_argc);
        } else {
          fprintf(stderr, "%s:%s:%d: include requires a filename argument.\n",
                  CMDLINE_PARSER_PACKAGE, filename, line_num);
        }
        continue;
      }
      len = strlen(fopt);
      strcat (my_argv, len > 1 ? "--" : "-");
      strcat (my_argv, fopt);
      if (len > 1 && ((farg && *farg) || equal))
        strcat (my_argv, "=");
      if (farg && *farg)
        strcat (my_argv, farg);
      ++(*my_argc);

      cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
      cmd_line_list_tmp->next = cmd_line_list;
      cmd_line_list = cmd_line_list_tmp;
      cmd_line_list->string_arg = gengetopt_strdup(my_argv);
    } /* while */

  if (file)
    fclose(file);
  return result;
}

int
cmdline_parser_configfile (
  const char *filename,
                           struct gengetopt_args_info *args_info,
                           int override, int initialize, int check_required)
{
  struct cmdline_parser_params params;

  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;
  
  return cmdline_parser_config_file (filename, args_info, &params);
}

int
cmdline_parser_config_file (const char *filename,
                           struct gengetopt_args_info *args_info,
                           struct cmdline_parser_params *params)
{
  int i, result;
  int my_argc = 1;
  char **my_argv_arg;
  char *additional_error;

  /* store the program name */
  cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
  cmd_line_list_tmp->next = cmd_line_list;
  cmd_line_list = cmd_line_list_tmp;
  cmd_line_list->string_arg = gengetopt_strdup (CMDLINE_PARSER_PACKAGE);

  result = _cmdline_parser_configfile(filename, &my_argc);

  if (result != EXIT_FAILURE) {
    my_argv_arg = (char **) malloc((my_argc+1) * sizeof(char *));
    cmd_line_list_tmp = cmd_line_list;

    for (i = my_argc - 1; i >= 0; --i) {
      my_argv_arg[i] = cmd_line_list_tmp->string_arg;
      cmd_line_list_tmp = cmd_line_list_tmp->next;
    }

    my_argv_arg[my_argc] = 0;

    additional_error = (char *)malloc(strlen(filename) + strlen(ADDITIONAL_ERROR) + 1);
    strcpy (additional_error, ADDITIONAL_ERROR);
    strcat (additional_error, filename);
    result =
      cmdline_parser_internal (my_argc, my_argv_arg, args_info,
                              params,
                              additional_error);

    free (additional_error);
    free (my_argv_arg);
  }

  free_cmd_list();
  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}